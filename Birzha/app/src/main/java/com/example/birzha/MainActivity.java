package com.example.birzha;
import android.app.Activity;
import android.os.Bundle;
import android.widget.ListView;

public class MainActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        MyIndexAdapter adapter = new MyIndexAdapter(this, makeMonth());
        ListView lv = (ListView) findViewById(R.id.listView);
        lv.setAdapter(adapter);
    }

    // Метод cоздания массива месяцев
    MyIndex[] makeMonth() {
        MyIndex[] arr = new MyIndex[12];

// Названия месяцев
        String[] monthArr = {"Apple", "Samsung", "LG", "D&J", "EA", "Golden Sucks", "Penta", "Intel", "Nokia", "Bentley", "NSB", "Tesla"};
// Среднесуточная температура
        double[] Income = {-12.7, -11.3, -4.5, 7.7, 19.3, 23.9, 23.5, 22.8, 16.0, 5.2, -0.3, -9.3};
// Количество дней
        double[] Price = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// Сборка месяцев
        for (int i = 0; i < arr.length; i++) {
            MyIndex index = new MyIndex();
            index.name = monthArr[i];
            index.income = Income[i];
            index.price = Price[i];
            arr[i] = index;
        }
        return arr;
    }
}
