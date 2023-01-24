package com.example.pizzaexpress;

import android.content.Intent;
import android.os.Bundle;
import android.widget.ListView;

import androidx.appcompat.app.AppCompatActivity;

import java.util.ArrayList;

public class PizzaList extends AppCompatActivity {

    private ListView pizzaListView;

    private void setupUIviews(){
        pizzaListView = findViewById(R.id.listview_pizza_id);
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_pizza_list);

        setupUIviews();

        Intent intent = getIntent();
        String firstName = intent.getStringExtra("firstName");
        String lastName = intent.getStringExtra("lastName");
        String type = intent.getStringExtra("foodType");

        ArrayList<Pizza> pizzaList = new ArrayList<>();

        if (type.equals("veg"))
        {
            Pizza onion = new Pizza("Onions Pizza",  R.drawable.onion_pizza);
            Pizza margherita = new Pizza("Margherita Pizza", R.drawable.margherita_pizza);

            pizzaList.add(onion);
            pizzaList.add(margherita);
        }
        else
        {
            Pizza onion = new Pizza("Onions Pizza Non Veg",  R.drawable.onion_pizza);
            Pizza margherita = new Pizza("Margherita Pizza Non Veg", R.drawable.margherita_pizza);

            pizzaList.add(onion);
            pizzaList.add(margherita);
        }

        // Create pizza objects

        PizzaListAdapter adapter = new  PizzaListAdapter(this, R.layout.pizza, pizzaList);
        pizzaListView.setAdapter(adapter);
    }
}