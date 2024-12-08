package org.example;

import jakarta.persistence.DiscriminatorValue;
import jakarta.persistence.Entity;
import jakarta.persistence.Table;

@Entity
@Table( name = "rectangles" )
public class Rectangle extends Shape {

    private double width;
    private double height;

    private double x;
    private double y;

    public Rectangle(double x, double y, double width, double height, Color color) {
        super(color);
        this.x = x;
        this.y = y;
        this.width = width;
        this.height = height;
    }

    public Rectangle() {
    }

    @Override
    public double getArea() {
        return this.width * this.height;
    }

    @Override
    public double getPerimeter() {
        return 2 * this.width + 2 * this.height;
    }

    public double getWidth() {
        return width;
    }

    public void setWidth(double width) {
        this.width = width;
    }

    public double getHeight() {
        return height;
    }

    public void setHeight(double height) {
        this.height = height;
    }

    public double getX() {
        return x;
    }

    public void setX(double x) {
        this.x = x;
    }

    public double getY() {
        return y;
    }

    public void setY(double y) {
        this.y = y;
    }

    @Override
    public String getColorDescription() {
        Color color = getColor();
        return String.format("Rectangle color: [R=%d, G=%d, B=%d, A=%.2f]",
                color.getR(), color.getG(), color.getB(), color.getA() / 255.0);
    }

    @Override
    public void printShapeName() {
        System.out.println("Rectangle");
    }
}