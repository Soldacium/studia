package org.example;

import org.junit.Test;

import static org.junit.Assert.*;

public class ShapeDescriberTest {

    @Test
    public void testDescribeWithRectangle() {
        Rectangle rectangle = new Rectangle(0, 0, 10, 20, new Color(255, 0, 0));
        ShapeDescriber describer = new ShapeDescriber();

        java.io.ByteArrayOutputStream outContent = new java.io.ByteArrayOutputStream();
        System.setOut(new java.io.PrintStream(outContent));

        describer.describe(rectangle);

        String output = outContent.toString();
        assertTrue(output.contains("Area: 200.0"));
        assertTrue(output.contains("Perimeter: 60.0"));

        System.setOut(System.out);
    }

    @Test
    public void testDescribeWithTriangle() {
        Triangle triangle = new Triangle(3, 4, 5, new Color(0, 255, 0));
        ShapeDescriber describer = new ShapeDescriber();

        java.io.ByteArrayOutputStream outContent = new java.io.ByteArrayOutputStream();
        System.setOut(new java.io.PrintStream(outContent));
        describer.describe(triangle);

        String output = outContent.toString();
        assertTrue(output.contains("Area: 6.0"));
        assertTrue(output.contains("Perimeter: 12.0"));

        System.setOut(System.out);
    }
}