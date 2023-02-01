package com.example.pizzaexpress;

import android.content.Intent;
import android.os.Bundle;
import android.widget.Button;
import android.widget.EditText;

import androidx.appcompat.app.AppCompatActivity;

public class MainActivity extends AppCompatActivity {

    private Button makeOrderBtn;
    private EditText firstName;
    private EditText lastName;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        setupUIviews();

        makeOrderBtn.setOnClickListener(view -> {
            String firstNameStr = firstName.getText().toString();
            String lastNameStr = lastName.getText().toString();

            Intent intent = new Intent(getApplicationContext(), VegNonVegSelection.class);

            intent.putExtra("firstName", firstNameStr);
            intent.putExtra("lastName", lastNameStr);

            startActivity(intent);
        });
    }

    private void setupUIviews(){
        makeOrderBtn = findViewById (R.id.makeOrder_btn_id);
        firstName = findViewById (R.id.firstName_id);
        lastName = findViewById (R.id.lastName_id);
    }


}