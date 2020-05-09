package com.example.retrofittest;


import retrofit2.Call;
import retrofit2.http.Body;
import retrofit2.http.GET;
import retrofit2.http.POST;
import retrofit2.http.Path;

public interface JSONPlaceHolderApi {
    @GET("/posts/{id}")
    Call<Post> getPostWithID(@Path("id") int id);
    @POST("/addUser")
    Call<Post> postData(@Body Post data);
}
