package com.example.pizzaexpress;

import android.content.Intent;
import android.os.Bundle;
import android.widget.Button;
import android.widget.EditText;

import androidx.appcompat.app.AppCompatActivity;

public class Address extends AppCompatActivity {

    private EditText address1;
    private EditText address2;
    private EditText pincode;
    private EditText district;
    private EditText state;
    private Button confirmOrderBtn;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_address);

        setupUIviews();

        Intent newIntent = getIntent();
        String firstName = newIntent.getStringExtra("firstName");
        String lastName = newIntent.getStringExtra("lastName");
        String totalPrice = newIntent.getStringExtra("totalPrice");
        String pizzaName = newIntent.getStringExtra("pizzaName");

        confirmOrderBtn.setOnClickListener(view -> {
            Intent intent = new Intent(getApplicationContext(), OrderSummary.class);

            intent.putExtra("firstName", firstName);
            intent.putExtra("lastName", lastName);
            intent.putExtra("totalPrice", totalPrice);
            intent.putExtra("address1", address1.getText().toString());
            intent.putExtra("address2", address2.getText().toString());
            intent.putExtra("pincode", pincode.getText().toString());
            intent.putExtra("district", district.getText().toString());
            intent.putExtra("state", state.getText().toString());
            intent.putExtra("pizzaName", pizzaName);

            startActivity(intent);
        });


    }

    private void setupUIviews(){
        address1 = findViewById (R.id.address1);
        address2 = findViewById (R.id.address2);
        pincode = findViewById (R.id.pincode);
        district = findViewById (R.id.district);
        state = findViewById (R.id.state);
        confirmOrderBtn = findViewById(R.id.confirm_btn);
    }
}