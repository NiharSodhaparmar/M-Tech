package com.example.pizzaexpress;

import android.annotation.SuppressLint;
import android.os.Bundle;
import android.view.View;
import android.widget.CheckBox;
import android.widget.RadioButton;
import android.widget.TextView;

import androidx.appcompat.app.AppCompatActivity;

public class Topings extends AppCompatActivity {

    Pizza pizza;
    TextView total;

    double total_price;

    @SuppressLint("MissingInflatedId")
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_topings);

        pizza = new Pizza();
        total = findViewById(R.id.idTotalPrice);

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
        total_price = pizza.getPizza_size_price() + pizza.getCheese_price() + pizza.getPepperoni_price() + pizza.getSpinach_price();
        return total_price;
    }

}