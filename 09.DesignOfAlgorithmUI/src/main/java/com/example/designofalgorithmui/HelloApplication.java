package com.example.designofalgorithmui;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.scene.image.Image;
import javafx.stage.Stage;

import java.io.IOException;

public class HelloApplication extends Application {
    @Override
    public void start(Stage stage) throws IOException {
        FXMLLoader fxmlLoader = new FXMLLoader(HelloApplication.class.getResource("hello-view.fxml"));
        Scene scene = new Scene(fxmlLoader.load(), 1105, 660);
        stage.setTitle("Design & Analysis of Algorithms");
        stage.setScene(scene);
        stage.show();
        stage.setResizable(false);
        stage.getIcons().add(new Image(getClass().getResourceAsStream("/com/example/designofalgorithmui/images/ProgramIcon.png")));
    }

    public static void main(String[] args) {
        launch();
    }
}