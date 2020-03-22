package com.example.a420;
import android.os.AsyncTask;
import android.os.Bundle;
import android.os.Environment;
import android.widget.TextView;

import androidx.appcompat.app.AppCompatActivity;

import java.io.File;

public class MainActivity extends AppCompatActivity {

    //строка для хранения списка директорий
    private StringBuilder strTree = new StringBuilder();

    //поле для вывода результатов работы программы на экран
    private TextView logTview;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        logTview = (TextView) findViewById(R.id.tvLog);
        //Создаем AsyncTask для работы с рекурсией
        assyncRecursion task = new assyncRecursion();
        //Запускаем AsyncTask
        task.execute();
    }

    //Класс для выполнения тяжелых задач в отдельном потоке и передача в UI-поток результатов работы.
    private class assyncRecursion extends AsyncTask<Void, Void, Void> {

        /*Рекурсивный метод формирует текст со списком директорий
        String path - путь к директории
        String indent - строка, иллюстрирующая глубину вложения директории (длина ветки дерева директорий),
        за каждый уровень добавляем --
        */
        private void recursiveCall(String path, String indent) {
            //получаем список файлов и директорий внутри текущей директории
            File[] fileList = new File(path).listFiles();
            for (File file : fileList) {
                if (file.isDirectory()) { //для каждой директории из списка
                    //сохраняем глубину вложения и имя директории в строку strTree
                    strTree.append(indent).append(file.getName()).append("\n");
                    //рекурсивный вызов для каждой директории из списка
                    recursiveCall(file.getAbsolutePath(), indent + "-- ");
                }
            }
        }

        //Метод выполняется в отдельном потоке, нет доступа к UI
        @Override
        protected Void doInBackground(Void... params) {
            //вызов метода с корневой папкой внешней памяти, глубина 0
            recursiveCall(Environment.getExternalStorageDirectory().getPath(), "");
            return null;
        }

        //Метод выполняется после doInBackground, есть доступ к UI
        @Override
        protected void onPostExecute(Void result) {
            super.onPostExecute(result);
            //отображаем сформированный текст со списком директорий
            logTview.setText(strTree);
        }

    }
}