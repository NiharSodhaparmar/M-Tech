package com.example.pizzaexpress;

public class Pizza {
    private String name;
    private int imgURL;
    private double pizza_size_price;
    private double cheese_price = 0;
    private double spinach_price = 0;
    private double pepperoni_price = 0;

    public Pizza(String name, int imgURL) {
        this.name = name;
        this.imgURL = imgURL;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getImgURL() {
        return imgURL;
    }

    public void setImgURL(int imgURL) {
        this.imgURL = imgURL;
    }

    public double getPizza_size_price() {
        return pizza_size_price;
    }

    public void setPizza_size_price(double pizza_size_price) {
        this.pizza_size_price = pizza_size_price;
    }

    public double getCheese_price() {
        return cheese_price;
    }

    public void setCheese_price(double cheese_price) {
        this.cheese_price = cheese_price;
    }

    public double getSpinach_price() {
        return spinach_price;
    }

    public void setSpinach_price(double spinach_price) {
        this.spinach_price = spinach_price;
    }

    public double getPepperoni_price() {
        return pepperoni_price;
    }

    public void setPepperoni_price(double pepperoni_price) {
        this.pepperoni_price = pepperoni_price;
    }

    public Pizza() {
    }

}
