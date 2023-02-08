package com.example.pizzaexpress;

import android.annotation.SuppressLint;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.CheckBox;
import android.widget.RadioButton;
import android.widget.TextView;
import android.widget.Toast;

import androidx.appcompat.app.AppCompatActivity;

public class Topings extends AppCompatActivity {

    private Button addToCartBtn;
    private Button goToCart;
    private TextView total;
    private Pizza pizza;
    double totalPrice;
    private DBHandler dbHandler;
    int pizzaQuantity = 1;

    @SuppressLint("MissingInflatedId")
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_topings);
        setupUIviews();

        Intent newIntent = getIntent();
        String pizzaName = newIntent.getStringExtra("pizzaName");;

        addToCartBtn.setOnClickListener(view -> {
            dbHandler = new DBHandler(getApplicationContext());

            if (pizzaName.isEmpty() && pizzaQuantity == 0 && totalPrice == 0) {
                Toast.makeText(getApplicationContext(), "Order Not Valid..", Toast.LENGTH_SHORT).show();
                return;
            }

            // on below line we are calling a method to add new
            // course to sqlite data and pass all our values to it.
            dbHandler.addNewPizza(pizzaName, pizzaQuantity+"", (int)totalPrice+"");

            // after adding the data we are displaying a toast message.
            Toast.makeText(getApplicationContext(), "Pizza has been added to cart.", Toast.LENGTH_SHORT).show();

            Intent intent = new Intent(getApplicationContext(), VegNonVegSelection.class);

            startActivity(intent);
        });

        goToCart.setOnClickListener(view -> {
            Intent intent = new Intent(getApplicationContext(), OrderSummary.class);

            startActivity(intent);
        });
    }

    private void setupUIviews(){
        addToCartBtn = findViewById (R.id.next_btn_id);
        goToCart = findViewById(R.id.go_to_cart);
        total = findViewById (R.id.idTotalPrice);
        pizza = new Pizza();
    }

    public void radioClicked(View view) {

        boolean checked = ((RadioButton) view).isChecked();

        switch (view.getId()) {

            case R.id.idSizeRBSmall:
                if (checked)
                    pizza.setPizza_size_price(9);
                break;

            case R.id.idSizeRBMedium:
                if (checked)
                    pizza.setPizza_size_price(10);
                break;

            case R.id.idSizeRBLarge:
                if (checked)
                    pizza.setPizza_size_price(11);
                break;
        }
        total.setText("Total Price: " + calculatePrice() + " $");
    }

    public void onCheckboxClicked(View view){

        boolean checked = ((CheckBox) view).isChecked();

        switch (view.getId()){

            case R.id.idToppingCBCheese:
                if(checked)
                    pizza.setCheese_price(2);
                else
                    pizza.setCheese_price(0);
                break;

            case R.id.idToppingCBPepperoni:
                if(checked)
                    pizza.setPepperoni_price(2);
                else
                    pizza.setPepperoni_price(0);
                break;

            case R.id.idToppingCBSpinach:
                if(checked)
                    pizza.setSpinach_price(2);
                else
                    pizza.setSpinach_price(0);
                break;
        }
        total.setText("Total Price: " + calculatePrice() + " $");
    }

    private double calculatePrice(){
        totalPrice = pizza.getPizza_size_price() + pizza.getCheese_price() + pizza.getPepperoni_price() + pizza.getSpinach_price();
        return totalPrice;
    }

}