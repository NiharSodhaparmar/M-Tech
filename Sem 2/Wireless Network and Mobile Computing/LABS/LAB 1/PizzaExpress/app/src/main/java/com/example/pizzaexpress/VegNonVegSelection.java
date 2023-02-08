package com.example.pizzaexpress;

import android.content.Intent;
import android.os.Bundle;
import android.widget.Button;

import androidx.appcompat.app.AppCompatActivity;

public class VegNonVegSelection extends AppCompatActivity {

    private Button vegBtn;
    private  Button nonVegBtn;
    private  Button goToCartBtn;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_veg_non_veg_selection);
        setupUIviews();

        vegBtn.setOnClickListener(view -> {
            Intent newIntent = new Intent(getApplicationContext(), PizzaList.class);
            newIntent.putExtra("foodType", "veg");
            startActivity(newIntent);
        });

        nonVegBtn.setOnClickListener(view -> {
            Intent newIntent = new Intent(getApplicationContext(), PizzaList.class);
            newIntent.putExtra("foodType", "nonVeg");
            startActivity(newIntent);
        });

        goToCartBtn.setOnClickListener(view -> {
            Intent newIntent = new Intent(getApplicationContext(), OrderSummary.class);
            startActivity(newIntent);
        });

    }

    private void setupUIviews(){
        vegBtn = findViewById (R.id.veg_btn_id);
        nonVegBtn = findViewById (R.id.non_veg_btn_id);
        goToCartBtn = findViewById(R.id.go_to_cart_btn_id);
    }
}