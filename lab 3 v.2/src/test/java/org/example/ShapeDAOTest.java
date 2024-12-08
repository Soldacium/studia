package org.example;

import org.example.repository.ShapeRepository;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;

import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

@SpringBootTest
public class ShapeDAOTest {

    @Autowired
    private ShapeRepository shapeRepository;

    @Test
    public void testSaveAndRetrieveShape() {
        // Przygotowanie danych
        Color blue = new Color(0, 0, 255);
        Rectangle rectangle = new Rectangle(10, 20, 10, 10, blue);

        // Zapisz obiekt
        shapeRepository.save(rectangle);

        // Pobierz wszystkie kształty
        List<Shape> shapes = shapeRepository.findAll();
        assertFalse(shapes.isEmpty(), "Baza danych powinna zawierać co najmniej jeden obiekt");

        // Pobierz pierwszy kształt i sprawdź dane
        Shape retrievedShape = shapes.get(0);
        assertTrue(retrievedShape instanceof Rectangle, "Oczekiwano obiektu typu Rectangle");
        Rectangle retrievedRectangle = (Rectangle) retrievedShape;

        assertEquals(10, retrievedRectangle.getWidth());
        assertEquals(20, retrievedRectangle.getHeight());
        assertEquals(255, retrievedRectangle.getColor().getB());

        shapeRepository.delete(retrievedShape);
    }

    @Test
    public void testDeleteShape() {
        // Przygotowanie danych
        Color red = new Color(255, 0, 0);
        Rectangle rectangle = new Rectangle(15, 25,10,10, red);

        shapeRepository.save(rectangle);

        shapeRepository.delete(rectangle);

        List<Shape> shapes = shapeRepository.findAll();
        assertTrue(shapes.isEmpty(), "Baza danych powinna być pusta po usunięciu obiektu");
    }

    @Test
    public void testUpdateShape() {
        Color green = new Color(0, 255, 0);
        Rectangle rectangle = new Rectangle(5, 10, 10, 10, green);

        shapeRepository.save(rectangle);

        rectangle.setWidth(50);
        rectangle.setHeight(100);
        shapeRepository.save(rectangle);

        List<Shape> shapes = shapeRepository.findAll();
        assertFalse(shapes.isEmpty(), "Baza danych powinna zawierać zaktualizowany obiekt");

        Shape retrievedShape = shapes.get(0);
        assertTrue(retrievedShape instanceof Rectangle, "Oczekiwano obiektu typu Rectangle");
        Rectangle retrievedRectangle = (Rectangle) retrievedShape;

        assertEquals(50, retrievedRectangle.getWidth());
        assertEquals(100, retrievedRectangle.getHeight());

        shapeRepository.delete(rectangle);
    }
}