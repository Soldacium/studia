package org.example;

import jakarta.persistence.Embeddable;

@Embeddable
public class Color {

    private int r;
    private int g;
    private int b;
    private int a;

    public Color(int r, int g, int b, int a) {
        this.r = r;
        this.g = g;
        this.b = b;
        this.a = a;
    }

    public Color(int r, int g, int b) {
        this(r, g, b, 0);
    }

    public Color() {
    }

    public int getR() {
        return r;
    }

    public void setR(int r) {
        this.r = r;
    }

    public int getG() {
        return g;
    }

    public void setG(int g) {
        this.g = g;
    }

    public int getB() {
        return b;
    }

    public void setB(int b) {
        this.b = b;
    }

    public int getA() {
        return a;
    }

    public void setA(int a) {
        this.a = a;
    }

    public String getColorString() {
        return String.format("rgba(%d, %d, %d, %.2f)", r, g, b, a / 255.0);
    }

    @Override
    public String toString() {
        return getColorString();
    }
}