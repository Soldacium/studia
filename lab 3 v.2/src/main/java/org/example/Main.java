package org.example;

public class Main {
    public static void main(String[] args) {
        Color red = new Color(255, 0, 0);
        Rectangle rect = new Rectangle(0, 0, 100, 100, red);
        ShapeDescriber describer = new ShapeDescriber();

        describer.describe(rect);
    }
}