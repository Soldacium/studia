package org.example;

import org.junit.Test;

import static org.junit.Assert.*;

public class ColorTest {

    @Test
    public void testValidColorCreation() {
        Color color = new Color(255, 0, 0, 128);
        assertEquals("255, 0, 0, 128", color.getColorString());
    }

    @Test
    public void testInvalidColorCreation() {
        try {
            new Color(-1, 300, 256, 0);
            fail("Expected IllegalArgumentException");
        } catch (IllegalArgumentException e) {
            assertTrue(e.getMessage().contains("Invalid color"));
        }
    }

    @Test
    public void testDefaultAlphaChannel() {
        Color color = new Color(0, 255, 255);
        assertEquals("0, 255, 255, 0", color.getColorString());
    }
}