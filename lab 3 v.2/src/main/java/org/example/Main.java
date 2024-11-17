package org.example;

//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {
    public static void main(String[] args) {
        Color red = new Color(255, 0, 0);
        Rectangle rect = new Rectangle(0, 0, 100, 100, red);
        ShapeDescriber describer = new ShapeDescriber();

        describer.describe(rect);
    }
}