package org.example;

public abstract class Shape {
    Color color;
    public abstract double getArea();
    public abstract double getPerimeter();
    public Shape(Color color){
        this.color = color;
    };
    public void printShapeName(){
        System.out.println(this.getClass().getName());
    }
    public String getColorDesciption(){
        return ("Red: "+ color.r() + ", Green: " + color.g() + ", Blue: " +  color.b() + ", Alpha: " + color.a());
    }
}
