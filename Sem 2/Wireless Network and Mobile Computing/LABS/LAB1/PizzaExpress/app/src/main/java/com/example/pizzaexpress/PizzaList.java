package com.example.pizzaexpress;

import android.os.Bundle;
import android.widget.ListView;

import androidx.appcompat.app.AppCompatActivity;

import java.util.ArrayList;

public class PizzaList extends AppCompatActivity {

    private ListView pizzaListView;

    private void setupUIviews(){
        pizzaListView =  (ListView) findViewById(R.id.listview_pizza_id);
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_pizza_list);

        setupUIviews();

        // Create pizza objects
        Pizza onion = new Pizza("Onions Pizza",  R.drawable.onion_pizza);
        Pizza margherita = new Pizza("Margherita Pizza", R.drawable.margherita_pizza);

        ArrayList<Pizza> pizzaList = new ArrayList<>();
        pizzaList.add(onion);
        pizzaList.add(margherita);

        PizzaListAdapter adapter = new  PizzaListAdapter(this, R.layout.pizza, pizzaList);
        pizzaListView.setAdapter(adapter);
    }
}