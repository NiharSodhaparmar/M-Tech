package com.example.attendancesystem;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.app.ActivityCompat;
import androidx.core.content.ContextCompat;

import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

import android.Manifest;
import android.annotation.SuppressLint;
import android.content.IntentSender;
import android.content.pm.PackageManager;
import android.location.Location;
import android.os.Bundle;
import android.os.Handler;
import android.os.Looper;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

import com.google.android.gms.common.api.ResolvableApiException;
import com.google.android.gms.location.FusedLocationProviderClient;
import com.google.android.gms.location.LocationAvailability;
import com.google.android.gms.location.LocationCallback;
import com.google.android.gms.location.LocationRequest;
import com.google.android.gms.location.LocationResult;
import com.google.android.gms.location.LocationServices;
import com.google.android.gms.location.LocationSettingsRequest;
import com.google.android.gms.location.LocationSettingsResponse;
import com.google.android.gms.location.SettingsClient;
import com.google.android.gms.tasks.OnFailureListener;
import com.google.android.gms.tasks.OnSuccessListener;
import com.google.android.gms.tasks.Task;
import com.google.firebase.database.DataSnapshot;
import com.google.firebase.database.DatabaseError;
import com.google.firebase.database.DatabaseReference;
import com.google.firebase.database.FirebaseDatabase;
import com.google.firebase.database.ValueEventListener;

public class MainActivity extends AppCompatActivity {

    TextView tv_latitude, tv_longitude;

    EditText edit_enrollmentNum;

    Button btn_Present;
    Button btn_Absent;

    int LOCATION_REQUEST_CODE = 1001;

    FusedLocationProviderClient fusedLocationProviderClient;

    LocationRequest locationRequest;

    LocationCallback mCallback;


    Handler handler = new Handler();
    Runnable runnable;
    int delay = 10000;

    FirebaseDatabase database;

    DatabaseReference myRef, myRef1, myRef2, myRef3, myRef4;

    String currentDate;

    public static double LATITUDE_min = 21.21125;
    public static double LATITUDE_max = 21.21135;

    public static double LONGITUDE_min = 72.89401;
    public static double LONGITUDE_max = 72.89420;

    double current_latitude;
    double current_longitude;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        set_view();


        database = FirebaseDatabase.getInstance();
        myRef = database.getReference(currentDate);
        myRef1 = database.getReference("LATITUDE_min");
        myRef2 = database.getReference("LATITUDE_max");
        myRef3 = database.getReference("LONGITUDE_min");
        myRef4 = database.getReference("LONGITUDE_max");
        getLastLocation();


        mCallback = new LocationCallback() {
            //This callback is where we get "streaming" location updates. We can check things like accuracy to determine whether
            //this latest update should replace our previous estimate.
            @Override
            public void onLocationResult(LocationResult locationResult) {
                if (locationResult == null) {
                    Log.d("MainActivity", "locationResult null");
                    return;
                }
                Log.d("MainActivity", "received " + locationResult.getLocations().size() + " locations");

            }

            @Override
            public void onLocationAvailability(LocationAvailability locationAvailability) {
                Log.d("MainActivity", "locationAvailability is " + locationAvailability.isLocationAvailable());
                super.onLocationAvailability(locationAvailability);
            }
        };

        LocationSettingsRequest.Builder builder = new LocationSettingsRequest.Builder()
                .addLocationRequest(locationRequest);

        //This checks whether the GPS mode (high accuracy,battery saving, device only) is set appropriately for "mRequest". If the current settings cannot fulfil
        //mRequest(the Google Fused Location Provider determines these automatically), then we listen for failutes and show a dialog box for the user to easily
        //change these settings.
        SettingsClient client = LocationServices.getSettingsClient(MainActivity.this);
        Task<LocationSettingsResponse> task = client.checkLocationSettings(builder.build());
        task.addOnFailureListener(new OnFailureListener() {
            @Override
            public void onFailure(@NonNull Exception e) {
                if (e instanceof ResolvableApiException) {
                    // Location settings are not satisfied, but this can be fixed
                    // by showing the user a dialog.
                    try {
                        // Show the dialog by calling startResolutionForResult(),
                        // and check the result in onActivityResult().
                        ResolvableApiException resolvable = (ResolvableApiException) e;
                        resolvable.startResolutionForResult(MainActivity.this, 500);
                    } catch (IntentSender.SendIntentException sendEx) {
                        // Ignore the error.
                    }
                }
            }
        });


        myRef1.addValueEventListener(new ValueEventListener() {
            @Override
            public void onDataChange(DataSnapshot dataSnapshot) {
                // This method is called once with the initial value and again
                // whenever data at this location is updated.
                LATITUDE_min = Double.parseDouble(dataSnapshot.getValue() + "");
                Log.d("MainActivity", "Value is: " + LATITUDE_min + "");
            }

            @Override
            public void onCancelled(DatabaseError error) {
                // Failed to read value
                Log.w("MainActivity", "Failed to read value.", error.toException());
            }
        });

        myRef2.addValueEventListener(new ValueEventListener() {
            @Override
            public void onDataChange(DataSnapshot dataSnapshot) {
                // This method is called once with the initial value and again
                // whenever data at this location is updated.
                LATITUDE_max = Double.parseDouble(dataSnapshot.getValue() + "");
                Log.d("MainActivity", "Value is: " + LATITUDE_max + "");
            }

            @Override
            public void onCancelled(DatabaseError error) {
                // Failed to read value
                Log.w("MainActivity", "Failed to read value.", error.toException());
            }
        });

        myRef3.addValueEventListener(new ValueEventListener() {
            @Override
            public void onDataChange(DataSnapshot dataSnapshot) {
                // This method is called once with the initial value and again
                // whenever data at this location is updated.
                LONGITUDE_min = Double.parseDouble(dataSnapshot.getValue() + "");
                Log.d("MainActivity", "Value is: " + LONGITUDE_min + "");
            }

            @Override
            public void onCancelled(DatabaseError error) {
                // Failed to read value
                Log.w("MainActivity", "Failed to read value.", error.toException());
            }
        });

        myRef4.addValueEventListener(new ValueEventListener() {
            @Override
            public void onDataChange(DataSnapshot dataSnapshot) {
                // This method is called once with the initial value and again
                // whenever data at this location is updated.
                LONGITUDE_max = Double.parseDouble(dataSnapshot.getValue() + "");
                Log.d("MainActivity", "Value is: " + LONGITUDE_max + "");
            }

            @Override
            public void onCancelled(DatabaseError error) {
                // Failed to read value
                Log.w("MainActivity", "Failed to read value.", error.toException());
            }
        });

        btn_Present.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                getLastLocation();
                if (check_valid_location()) {
                    String stu_enrollment = edit_enrollmentNum.getText().toString();
                    double latitude = Double.parseDouble(tv_latitude.getText().toString());
                    double longitude = Double.parseDouble(tv_longitude.getText().toString());

                    Student student = new Student(stu_enrollment, "Present", latitude, longitude);

                    myRef.child(stu_enrollment).setValue(student);

//                myRfe.setValue("Hello Rohit");
                    Toast.makeText(MainActivity.this, "Present", Toast.LENGTH_SHORT).show();
                } else {
                    Toast.makeText(MainActivity.this, "Check Location", Toast.LENGTH_SHORT).show();
                }

            }
        });

        btn_Absent.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                getLastLocation();
                if (check_valid_location()) {
                    String stu_enrollment = edit_enrollmentNum.getText().toString();
                    double latitude = Double.parseDouble(tv_latitude.getText().toString());
                    double longitude = Double.parseDouble(tv_longitude.getText().toString());

                    Student student = new Student(stu_enrollment, "Absent", latitude, longitude);

                    myRef.child(stu_enrollment).setValue(student);

//                myRfe.setValue("Hello Rohit");
                    Toast.makeText(MainActivity.this, "Absent", Toast.LENGTH_SHORT).show();
                } else {
                    Toast.makeText(MainActivity.this, "Check Location", Toast.LENGTH_SHORT).show();
                }

            }
        });

    }

    @Override
    protected void onResume() {
        handler.postDelayed(runnable = new Runnable() {
            public void run() {
                handler.postDelayed(runnable, delay);
                getLastLocation();
            }
        }, delay);
        super.onResume();
        startLocationUpdates();
    }
    //
    @Override
    protected void onPause() {
        super.onPause();
        handler.removeCallbacks(runnable); //stop handler when activity not visible super.onPause();
        fusedLocationProviderClient.removeLocationUpdates(mCallback);
    }

    @SuppressLint("MissingPermission")
    protected void startLocationUpdates() {
        fusedLocationProviderClient.requestLocationUpdates(locationRequest, mCallback, null);
    }

    @Override
    protected void onStart() {
        super.onStart();
        if (ContextCompat.checkSelfPermission(this, android.Manifest.permission.ACCESS_FINE_LOCATION) == PackageManager.PERMISSION_GRANTED) {
            getLastLocation();
        } else {
            askLocationPermission();
        }
    }

    @Override
    public void onRequestPermissionsResult(int requestCode, @NonNull String[] permissions, @NonNull int[] grantResults) {
        super.onRequestPermissionsResult(requestCode, permissions, grantResults);
        if (requestCode == LOCATION_REQUEST_CODE) {
            if (grantResults.length > 0 && grantResults[0] == PackageManager.PERMISSION_GRANTED) {
                getLastLocation();
            }
        }
    }


    boolean check_valid_location()
    {
        if((current_latitude >= LATITUDE_min) && (current_latitude <= LATITUDE_max) && (current_longitude >= LONGITUDE_min) && (current_longitude <= LONGITUDE_max))
        {
            return true;
        }
        return false;
    }


    private void askLocationPermission()
    {
        if(ContextCompat.checkSelfPermission(this , android.Manifest.permission.ACCESS_FINE_LOCATION) != PackageManager.PERMISSION_GRANTED)
        {
            if(ActivityCompat.shouldShowRequestPermissionRationale(this , Manifest.permission.ACCESS_FINE_LOCATION))
            {
                Log.d("MainActivity" , "askLocationPermission : you should show an alert dialog...");
                ActivityCompat.requestPermissions(this , new String[] {Manifest.permission.ACCESS_FINE_LOCATION} , LOCATION_REQUEST_CODE);
            }
            else
            {
                ActivityCompat.requestPermissions(this , new String[] {Manifest.permission.ACCESS_FINE_LOCATION} , LOCATION_REQUEST_CODE);
            }
        }

    }


    private void getLastLocation() {
        if (ActivityCompat.checkSelfPermission(this, Manifest.permission.ACCESS_FINE_LOCATION) != PackageManager.PERMISSION_GRANTED && ActivityCompat.checkSelfPermission(this, Manifest.permission.ACCESS_COARSE_LOCATION) != PackageManager.PERMISSION_GRANTED) {
            askLocationPermission();
        }
        else
        {
            fusedLocationProviderClient = LocationServices.getFusedLocationProviderClient(this);
            Task<Location> locationTask = fusedLocationProviderClient.getLastLocation();

            locationTask.addOnSuccessListener(new OnSuccessListener<Location>() {
                @Override
                public void onSuccess(Location location) {
                    updateUIView(location);
                }
            });

            locationTask.addOnFailureListener(new OnFailureListener() {
                @Override
                public void onFailure(@NonNull Exception e) {
                    Log.e("MainActivity" , "OnFailure : "+ e.getLocalizedMessage());
                }
            });
        }
    }

    private void updateUIView(Location location)
    {
        if(location != null)
        {
            Log.d("MainActivity" , "OnSuccess : Location updated...");
            current_longitude = location.getLongitude();
            current_latitude = location.getLatitude();

            tv_longitude.setText(String.valueOf(current_longitude));
            tv_latitude.setText(String.valueOf(current_latitude));

            if(check_valid_location()) {
                tv_longitude.setTextColor(getResources().getColor(R.color.green));
                tv_latitude.setTextColor(getResources().getColor(R.color.green));
            }
            else
            {
                tv_longitude.setTextColor(getResources().getColor(R.color.red));
                tv_latitude.setTextColor(getResources().getColor(R.color.red));
            }

//            Toast.makeText(MainActivity.this, "ok", Toast.LENGTH_SHORT).show();
        }
        else
        {
            Log.d("MainActivity" , "OnSuccess : Location was null...");
        }
    }

    void set_view() {
        tv_latitude = findViewById(R.id.tv_latitude);
        tv_longitude = findViewById(R.id.tv_longitude);

        edit_enrollmentNum = findViewById(R.id.edit_enrollmentNum);
        btn_Present = findViewById(R.id.btn_Present);
        btn_Absent = findViewById(R.id.btn_absent);

        locationRequest = new LocationRequest();

        locationRequest.setInterval(10000);

        locationRequest.setFastestInterval(5000);

        locationRequest.setPriority(LocationRequest.PRIORITY_HIGH_ACCURACY);

        currentDate = new java.sql.Date(System.currentTimeMillis()).toString();


    }

}