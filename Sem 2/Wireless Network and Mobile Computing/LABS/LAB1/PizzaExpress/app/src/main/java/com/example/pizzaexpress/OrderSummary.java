package com.example.pizzaexpress;

import android.content.Intent;
import android.os.Bundle;
import android.widget.TextView;

import androidx.appcompat.app.AppCompatActivity;

public class OrderSummary extends AppCompatActivity {

    private TextView orderSummary;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_order_summary);

        setupUIviews();

        Intent intent = getIntent();
        String firstName = intent.getStringExtra("firstName");
        String lastName = intent.getStringExtra("lastName");
        String address1 = intent.getStringExtra("address1");
        String address2 = intent.getStringExtra("address2");
        String pincode = intent.getStringExtra("pincode");
        String district = intent.getStringExtra("district");
        String state = intent.getStringExtra("state");
        String totalPrice = intent.getStringExtra("totalPrice");

        String orderSummaryText = "Name: " + firstName + lastName + "\n\n"
                + "Address : " + "\n" + address1 + ",\n" + address2 + ",\n" + pincode + ",\n" + district + ",\n" + state + "\n\n"
                + "Total Price: " + totalPrice;

        orderSummary.setText(orderSummaryText);

    }

    private void setupUIviews(){
        orderSummary = findViewById(R.id.orderSummary);
    }
}