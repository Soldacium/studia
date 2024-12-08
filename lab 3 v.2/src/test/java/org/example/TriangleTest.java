package org.example;

import org.junit.Test;

import static org.junit.Assert.*;

public class TriangleTest {

    @Test
    public void testTriangleArea() {
        Triangle triangle = new Triangle(3, 4, 5, new Color(0, 255, 0));
        assertEquals(6, triangle.getArea(), 0.01);
    }

    @Test
    public void testTrianglePerimeter() {
        Triangle triangle = new Triangle(3, 4, 5, new Color(0, 255, 0));
        assertEquals(12, triangle.getPerimeter(), 0.01);
    }
}