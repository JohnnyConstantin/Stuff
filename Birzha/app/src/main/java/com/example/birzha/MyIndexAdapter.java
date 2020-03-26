package com.example.birzha;
import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.CheckBox;
import android.widget.ImageView;
import android.widget.TextView;

public class MyIndexAdapter extends ArrayAdapter<MyIndex> {

    public MyIndexAdapter(Context context, MyIndex[] arr) {
        super(context, R.layout.adapter_item, arr);
    }

    @Override
    public View getView(int position, View convertView, ViewGroup parent) {

        final MyIndex month = getItem(position);

        if (convertView == null) {
            convertView = LayoutInflater.from(getContext()).inflate(R.layout.adapter_item, null);
        }

// Заполняем адаптер
        ((TextView) convertView.findViewById(R.id.textView)).setText(month.name);
        ((TextView) convertView.findViewById(R.id.textView2)).setText(String.valueOf(month.income));
        ((TextView) convertView.findViewById(R.id.textView3)).setText(String.valueOf(month.price));
// Выбираем картинку для месяца
        if (month.income > 0.)
            ((ImageView) convertView.findViewById(R.id.imageView)).setImageResource(R.drawable.up);
        else
            ((ImageView) convertView.findViewById(R.id.imageView)).setImageResource(R.drawable.down);

        return convertView;
    }
}
