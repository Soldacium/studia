package org.example;

import org.junit.Test;

import static org.junit.Assert.*;

public class RectangleTest {

    @Test
    public void testRectangleArea() {
        Rectangle rect = new Rectangle(0, 0, 10, 20, new Color(255, 0, 0));
        assertEquals(200, rect.getArea(), 0.01);
    }

    @Test
    public void testRectanglePerimeter() {
        Rectangle rect = new Rectangle(0, 0, 10, 20, new Color(255, 0, 0));
        assertEquals(60, rect.getPerimeter(), 0.01);
    }
}