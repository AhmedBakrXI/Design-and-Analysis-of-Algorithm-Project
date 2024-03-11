package com.example.designofalgorithmui;

import javafx.animation.ScaleTransition;
import javafx.fxml.FXML;
import javafx.scene.image.ImageView;
import javafx.scene.input.MouseDragEvent;
import javafx.util.Duration;

import java.awt.*;
import java.io.IOException;
import java.net.URI;
import java.net.URISyntaxException;


public class HelloController {

    @FXML
    private ImageView playBtn;
    @FXML
    private ImageView playBtn1;
    @FXML
    private ImageView playBtn2;
    @FXML
    private ImageView playBtn3;
    @FXML
    private ImageView playBtn4;
    @FXML
    private ImageView playBtn5;
    @FXML
    private ImageView playBtn6;
    @FXML
    private ImageView playBtn7;



    @FXML
    public void openTask1Link() {
        try {
            Desktop.getDesktop().browse(new URI("https://github.com/AhmedBakrXI/Design-and-Analysis-of-Algorithm-Project/tree/main/Task%201"));
        } catch (IOException | URISyntaxException e) {
            System.err.println("Can't open your browser!");
        }
    }

    @FXML
    public void openTask2Link() {
        try {
            Desktop.getDesktop().browse(new URI("https://github.com/AhmedBakrXI/Design-and-Analysis-of-Algorithm-Project/tree/main/Task%202"));
        } catch (IOException | URISyntaxException e) {
            System.err.println("Can't open your browser!");
        }
    }

    @FXML
    public void openTask3Link() {
        try {
            Desktop.getDesktop().browse(new URI("https://github.com/AhmedBakrXI/Design-and-Analysis-of-Algorithm-Project/tree/main/Task%203"));
        } catch (IOException | URISyntaxException e) {
            System.err.println("Can't open your browser!");
        }
    }

    @FXML
    public void openTask4Link() {
        try {
            Desktop.getDesktop().browse(new URI("https://github.com/AhmedBakrXI/Design-and-Analysis-of-Algorithm-Project/tree/main/Task%204"));
        } catch (IOException | URISyntaxException e) {
            System.err.println("Can't open your browser!");
        }
    }

    @FXML
    public void openTask5Link() {
        try {
            Desktop.getDesktop().browse(new URI("https://github.com/AhmedBakrXI/Design-and-Analysis-of-Algorithm-Project/tree/main/Task%205"));
        } catch (IOException | URISyntaxException e) {
            System.err.println("Can't open your browser!");
        }
    }

    @FXML
    public void openTask6Link() {
        try {
            Desktop.getDesktop().browse(new URI("https://github.com/AhmedBakrXI/Design-and-Analysis-of-Algorithm-Project/tree/main/Task%206"));
        } catch (IOException | URISyntaxException e) {
            System.err.println("Can't open your browser!");
        }
    }

    @FXML
    public void openTask7Link() {
        try {
            Desktop.getDesktop().browse(new URI("https://github.com/AhmedBakrXI/Design-and-Analysis-of-Algorithm-Project/tree/main/Task%207"));
        } catch (IOException | URISyntaxException e) {
            System.err.println("Can't open your browser!");
        }
    }

    @FXML
    public void openTask8Link() {
        try {
            Desktop.getDesktop().browse(new URI("https://github.com/AhmedBakrXI/Design-and-Analysis-of-Algorithm-Project/tree/main/Task%208"));
        } catch (IOException | URISyntaxException e) {
            System.err.println("Can't open your browser!");
        }
    }


    public void expandBtn() {
        ScaleTransition scaleTransition = new ScaleTransition(Duration.millis(200), playBtn);
        scaleTransition.setToX(1.1);
        scaleTransition.setToY(1.1);
        scaleTransition.play();
    }

    public void shrinkBtn() {
        ScaleTransition scaleTransition = new ScaleTransition(Duration.millis(200), playBtn);
        scaleTransition.setToX(1); // Reduce X scale factor
        scaleTransition.setToY(1); // Reduce Y scale factor
        scaleTransition.play();
    }

    public void expandBtn1() {
        ScaleTransition scaleTransition = new ScaleTransition(Duration.millis(200), playBtn1);
        scaleTransition.setToX(1.1);
        scaleTransition.setToY(1.1);
        scaleTransition.play();
    }

    public void shrinkBtn1() {
        ScaleTransition scaleTransition = new ScaleTransition(Duration.millis(200), playBtn1);
        scaleTransition.setToX(1); // Reduce X scale factor
        scaleTransition.setToY(1); // Reduce Y scale factor
        scaleTransition.play();
    }


    public void expandBtn2() {
        ScaleTransition scaleTransition = new ScaleTransition(Duration.millis(200), playBtn2);
        scaleTransition.setToX(1.1);
        scaleTransition.setToY(1.1);
        scaleTransition.play();
    }

    public void shrinkBtn2() {
        ScaleTransition scaleTransition = new ScaleTransition(Duration.millis(200), playBtn2);
        scaleTransition.setToX(1); // Reduce X scale factor
        scaleTransition.setToY(1); // Reduce Y scale factor
        scaleTransition.play();
    }


    public void expandBtn3() {
        ScaleTransition scaleTransition = new ScaleTransition(Duration.millis(200), playBtn3);
        scaleTransition.setToX(1.1);
        scaleTransition.setToY(1.1);
        scaleTransition.play();
    }

    public void shrinkBtn3() {
        ScaleTransition scaleTransition = new ScaleTransition(Duration.millis(200), playBtn3);
        scaleTransition.setToX(1); // Reduce X scale factor
        scaleTransition.setToY(1); // Reduce Y scale factor
        scaleTransition.play();
    }


    public void expandBtn4() {
        ScaleTransition scaleTransition = new ScaleTransition(Duration.millis(200), playBtn4);
        scaleTransition.setToX(1.1);
        scaleTransition.setToY(1.1);
        scaleTransition.play();
    }

    public void shrinkBtn4() {
        ScaleTransition scaleTransition = new ScaleTransition(Duration.millis(200), playBtn4);
        scaleTransition.setToX(1); // Reduce X scale factor
        scaleTransition.setToY(1); // Reduce Y scale factor
        scaleTransition.play();
    }


    public void expandBtn5() {
        ScaleTransition scaleTransition = new ScaleTransition(Duration.millis(200), playBtn5);
        scaleTransition.setToX(1.1);
        scaleTransition.setToY(1.1);
        scaleTransition.play();
    }

    public void shrinkBtn5() {
        ScaleTransition scaleTransition = new ScaleTransition(Duration.millis(200), playBtn5);
        scaleTransition.setToX(1); // Reduce X scale factor
        scaleTransition.setToY(1); // Reduce Y scale factor
        scaleTransition.play();
    }


    public void expandBtn6() {
        ScaleTransition scaleTransition = new ScaleTransition(Duration.millis(200), playBtn6);
        scaleTransition.setToX(1.1);
        scaleTransition.setToY(1.1);
        scaleTransition.play();
    }

    public void shrinkBtn6() {
        ScaleTransition scaleTransition = new ScaleTransition(Duration.millis(200), playBtn6);
        scaleTransition.setToX(1); // Reduce X scale factor
        scaleTransition.setToY(1); // Reduce Y scale factor
        scaleTransition.play();
    }


    public void expandBtn7() {
        ScaleTransition scaleTransition = new ScaleTransition(Duration.millis(200), playBtn7);
        scaleTransition.setToX(1.1);
        scaleTransition.setToY(1.1);
        scaleTransition.play();
    }

    public void shrinkBtn7() {
        ScaleTransition scaleTransition = new ScaleTransition(Duration.millis(200), playBtn7);
        scaleTransition.setToX(1); // Reduce X scale factor
        scaleTransition.setToY(1); // Reduce Y scale factor
        scaleTransition.play();
    }

    public void select1() {

    }

}