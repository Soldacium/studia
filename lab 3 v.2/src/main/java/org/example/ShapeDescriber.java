package org.example;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;


public class ShapeDescriber {
    public void describe(Shape shape) {
        System.out.println("Area: " + shape.getArea());
        System.out.println("Perimeter: " + shape.getPerimeter());

        logger.info(
                "Shape: " + shape.getClass().getSimpleName() +
                ", Color:" + shape.color.getColorString() +
                ", Area:" + shape.getArea() +
                ", Perimeter:" + shape.getPerimeter()
        );
    }

    public static final Logger logger = LoggerFactory.getLogger(ShapeDescriber.class);
}

