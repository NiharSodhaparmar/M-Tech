package com.example.pizzaexpress;

public class Pizza {
    private String name;
    private int imgURL;

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
}
