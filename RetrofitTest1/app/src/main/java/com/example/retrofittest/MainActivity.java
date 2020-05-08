package com.example.retrofittest;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

import okhttp3.OkHttpClient;
import okhttp3.logging.HttpLoggingInterceptor;
import retrofit2.Call;
import retrofit2.Callback;
import retrofit2.Response;
import retrofit2.Retrofit;
import retrofit2.converter.gson.GsonConverterFactory;

public class MainActivity extends AppCompatActivity {

    EditText name, mail, phone, pass;
    Button reg;
    TextView textViewres;
    private static final String BASE_URL = "https://languapp.herokuapp.com";
    private JSONPlaceHolderApi JSONPlaceHolderApi;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        textViewres = findViewById(R.id.textView);
        name = (EditText) findViewById(R.id.name);
        mail = (EditText) findViewById(R.id.mail);
        phone = (EditText) findViewById(R.id.phone);
        pass = (EditText) findViewById(R.id.pass);
        reg = (Button) findViewById(R.id.register);


        HttpLoggingInterceptor interceptor = new HttpLoggingInterceptor();
        interceptor.setLevel(HttpLoggingInterceptor.Level.BODY);

        OkHttpClient.Builder client = new OkHttpClient.Builder()
                .addInterceptor(interceptor);

        Retrofit retrofit = new Retrofit.Builder()
                .baseUrl(BASE_URL)
                .addConverterFactory(GsonConverterFactory.create())
                .client(client.build())
                .build();

        JSONPlaceHolderApi = retrofit.create(JSONPlaceHolderApi.class);

        reg.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                createPost();
            }
        });


    }

    public void createPost() {
    Post post = new Post(mail.getText().toString(),pass.getText().toString(),phone.getText().toString(),name.getText().toString());

    Call<Post> call = JSONPlaceHolderApi.postData(post);

    call.enqueue(new Callback<Post>() {
        @Override
        public void onResponse(Call<Post> call, Response<Post> response) {
            if(!response.isSuccessful()){
                textViewres.setText("code: " + response.code());
                return;
            }

            Post postResponse = response.body();

            String content = "";
            content += "Code: " + response.code() + "\n";
            content += "Name " + postResponse.getName() + "\n";
            content += "Mail " + postResponse.getMail() + "\n";
            content += "Pass " + postResponse.getPass() + "\n";
            content += "Phone " + postResponse.getPhone() + "\n";
            content += "Id " + postResponse.getId() + "\n";

            textViewres.setText(content);
        }

        @Override
        public void onFailure(Call<Post> call, Throwable t) {
        textViewres.setText(t.getMessage());
        }
    });
    }


}
