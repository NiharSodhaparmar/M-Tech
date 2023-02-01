package com.example.pizzaexpress;

import android.annotation.SuppressLint;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.CheckBox;
import android.widget.RadioButton;
import android.widget.TextView;

import androidx.appcompat.app.AppCompatActivity;

public class Topings extends AppCompatActivity {

    private Button nextBtn;
    private TextView total;
    private Pizza pizza;
    double totalPrice;

    @SuppressLint("MissingInflatedId")
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_topings);
        setupUIviews();

        Intent newIntent = getIntent();
        String firstName = newIntent.getStringExtra("firstName");
        String lastName = newIntent.getStringExtra("lastName");
        String pizzaName = newIntent.getStringExtra("pizzaName");

        nextBtn.setOnClickListener(view -> {
            Intent intent = new Intent(getApplicationContext(), Address.class);

            intent.putExtra("totalPrice",  Double.toString(totalPrice));
            intent.putExtra("firstName", firstName);
            intent.putExtra("lastName", lastName);
            intent.putExtra("pizzaName", pizzaName);

            startActivity(intent);
        });
    }

    private void setupUIviews(){
        nextBtn = findViewById (R.id.next_btn_id);
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