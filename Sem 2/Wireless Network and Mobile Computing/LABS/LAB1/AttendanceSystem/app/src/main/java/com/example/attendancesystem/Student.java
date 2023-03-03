package com.example.attendancesystem;

import android.util.Log;

import androidx.annotation.NonNull;

class Student {

    String EnrollNum;

    String Status;
    double latitude;
    double longitude;

    public Student(String enrollNum, String status, double latitude, double longitude) {
        EnrollNum = enrollNum;
        Status = status;
        this.latitude = latitude;
        this.longitude = longitude;
    }


    public String getEnrollNum() {
        return EnrollNum;
    }

    public double getLatitude() {
        return latitude;
    }

    public double getLongitude() {
        return longitude;
    }

    public String getStatus() {
        return Status;
    }

    @NonNull
    @Override
    public String toString() {
        Log.e("Student class" , this.EnrollNum);
        return this.EnrollNum;
    }
}