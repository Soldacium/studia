package org.example;

public record Color(int r, int g, int b, int a) {
    public Color {
        if(r < 0 || g < 0 || r > 255 || g > 255 || b < 0 || b > 255 || a < 0 || a > 255) {
            throw new IllegalArgumentException("Invalid color");
        }
    }
    public Color(int r, int g, int b) {
         this(r, g, b, 0);
    }

    public String getColorString(){
        return String.format("%d, %d, %d, %d", r, g, b, a);
    }

}