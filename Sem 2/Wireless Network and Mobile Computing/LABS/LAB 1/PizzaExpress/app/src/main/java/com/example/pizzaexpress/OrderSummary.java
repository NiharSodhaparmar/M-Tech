package com.example.pizzaexpress;

import android.content.Intent;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.os.Bundle;
import android.widget.Button;
import android.widget.TextView;

import androidx.appcompat.app.AppCompatActivity;

import java.util.ArrayList;

public class OrderSummary extends AppCompatActivity {

    private TextView orderSummary;
    private DBHandler dbHandler;
    ArrayList<String> pizzaName = new ArrayList<String>();
    ArrayList<String> pizzaPrice = new ArrayList<String>();
    ArrayList<String> pizzaQuantity = new ArrayList<String>();
    private Button placeOrderBtn;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_order_summary);

        setupUIviews();

        dbHandler = new DBHandler(getApplicationContext());

        SQLiteDatabase db = dbHandler.getReadableDatabase();
        String projection[] = {"pizza_name" , "Quantity" , "Price"};
        Cursor cursor = db.query("pizza_order" , projection ,null ,null ,null ,null ,null);

        String pizza_name ="";
        int total_price = 0;
        if(cursor != null)
        {
            cursor.moveToFirst();
        }

        if (cursor.getCount() > 0) {
            do {
                pizzaName.add(cursor.getString(0));
                pizzaPrice.add(cursor.getString(2));
                total_price += Integer.parseInt(cursor.getString(2));
                pizzaQuantity.add(cursor.getString(1));
            }
            while (cursor.moveToNext());
        }

        String orderSummaryText = "";

        for(int i = 0; i < pizzaName.size(); i++){
            orderSummaryText += "Pizza Name: " + pizzaName.get(i) + "\n"
                    + "Quantity: " + pizzaQuantity.get(i) + "\n"
                    + "Price: " + pizzaPrice.get(i) + "\n\n";
        }

        orderSummaryText += "Total Price: " + total_price + "\n\n";

        orderSummary.setText(orderSummaryText);

        placeOrderBtn.setOnClickListener(view -> {
            dbHandler.delete();
            Intent intent = new Intent(getApplicationContext(), Address.class);
            startActivity(intent);
        });

    }

    private void setupUIviews(){
        orderSummary = findViewById(R.id.orderSummary);
        placeOrderBtn = findViewById(R.id.place_order_button);
    }
}