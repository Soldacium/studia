package org.example;

public class Rectangle extends Shape{
    double width;
    double height;
    double x;
    double y;
    public Rectangle(double x, double y, double width, double height, Color color) {
        super(color);
        this.x = x;
        this.y = y;
        this.width = width;
        this.height = height;
    }
    @Override
    public double getArea() {
        return this.width * this.height;
    }
    @Override
    public double getPerimeter() {
        return 2 * this.width + 2 * this.height;
    }
}
