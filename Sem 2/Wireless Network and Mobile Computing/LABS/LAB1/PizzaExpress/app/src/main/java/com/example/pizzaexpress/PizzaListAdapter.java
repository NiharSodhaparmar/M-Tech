package com.example.pizzaexpress;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.ImageView;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;

import java.util.ArrayList;

public class PizzaListAdapter extends ArrayAdapter<Pizza> {

    private Context mContext;
    private int mResource;

    public PizzaListAdapter(@NonNull Context context, int resource, @NonNull ArrayList<Pizza> objects) {
        super(context, resource, objects);
        mContext = context;
        mResource = resource;
    }

    @NonNull
    @Override
    public View getView(int position, @Nullable View convertView, @NonNull ViewGroup parent) {
        String name = getItem(position).getName();
        int imgURL = getItem(position).getImgURL();

        Pizza pizza = new Pizza(name, imgURL);

        LayoutInflater inflater =  LayoutInflater.from(mContext);
        convertView = inflater.inflate(mResource, parent, false);

        TextView tvName = convertView.findViewById(R.id.name);
        ImageView image = convertView.findViewById(R.id.image);
        tvName.setText(name);
        image.setImageResource(imgURL);

        return convertView;
    }
}
