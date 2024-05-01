import javafx.animation.TranslateTransition;
import javafx.application.Application;
import javafx.geometry.Insets;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.TextField;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.layout.Pane;
import javafx.scene.layout.VBox;
import javafx.scene.text.Font;

import javafx.scene.text.FontWeight;
import javafx.scene.text.Text;
import javafx.stage.Stage;
import javafx.util.Duration;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


public class Main extends Application {
    private int key;

    public static void main(String[] args) {
        launch();
    }
    public static String execute(int x, int y) {
        try {
            String cppExecutablePath = "src/app.exe";
            String arguments = x + " " + y;

            Runtime runtime = Runtime.getRuntime();
            Process process = runtime.exec(cppExecutablePath + " " + arguments);

            BufferedReader reader = new BufferedReader(new InputStreamReader(process.getInputStream()));

            String line;
            StringBuilder output = new StringBuilder();
            while ((line = reader.readLine()) != null) {
                output.append(line).append("\n");
            }


            int exitCode = process.waitFor();
            System.out.println("Process exited with code " + exitCode);
            return output.toString();

        } catch (IOException | InterruptedException e) {
            e.printStackTrace();
        }
        return "Error";
    }
    @Override
    public void start(Stage primaryStage) {
        Pane pane = new Pane();
        Scene scene = new Scene(pane, 500, 500);
        TextField weightField = new TextField("Enter weight");
        TextField boxIndex = new TextField("Enter index of defected box");
        Button okBtn = new Button("OK");

        VBox vBox = new VBox(weightField, boxIndex, okBtn);
        vBox.setSpacing(50);
        vBox.setPadding(new Insets(50));

        Font font = Font.font("Consolas", FontWeight.BOLD, 24);
        Font font2 = Font.font("Consolas", FontWeight.BOLD, 18);

        Scene intro = new Scene(vBox, 500, 500);
        primaryStage.setScene(intro);
        final String[] currentWeight = new String[1];
        final Text[] weight = new Text[1];
        okBtn.setOnAction(e -> {
            currentWeight[0] = execute(Integer.parseInt(weightField.getText()), Integer.parseInt(boxIndex.getText()));
            weight[0] = new Text(currentWeight[0].replace("\n", "") + " KG");
            weight[0].setFont(font2);
            weight[0].setLayoutX(230);
            weight[0].setLayoutY(425);
            primaryStage.setScene(scene);
        });


        Box testBox = new Box(0, 200, 300);

        Box[] boxes = new Box[3];
        for (int i = 0; i < 3; i++) {
            Box box = new Box(i + 1, -50, -50);
            boxes[i] = box;
            pane.getChildren().addAll(box.getBox());
        }

        pane.getChildren().addAll(testBox.getBox());



        primaryStage.show();
        Text text = new Text("And So On till we reach 50!");

        ImageView balance = new ImageView("images/scale.png");
        balance.setScaleX(0.25);
        balance.setScaleY(0.25);
        balance.setLayoutX(-145);
        balance.setLayoutY(250);

        scene.setOnKeyPressed(e -> {
            if (key < 9) {
                int boxMove = key % 3;
                int boxID = key / 3;
                key++;
                switch (boxMove) {
                    case 0:
                        boxes[boxID].enterScene();
                        break;
                    case 1:
                        for (int i = 0; i <= boxID; i++)
                            boxes[boxID].getBalls(130, 170, i, pane);
                        break;
                    case 2:
                        boxes[boxID].leaveScene(pane);
                }
            } else if (key == 9) {
                key++;
                text.setLayoutX(60);
                text.setLayoutY(100);
                text.setFont(font);
                pane.getChildren().add(text);
            } else if (key == 10) {
                key++;
                TranslateTransition anim = new TranslateTransition(Duration.seconds(2), text);
                anim.setToX(1000);
                anim.play();
                anim.setOnFinished(event -> pane.getChildren().remove(text));
            } else if (key == 11) {
                key++;
                pane.getChildren().add(balance);
            } else if (key == 12) {
                key++;
                int w = Integer.parseInt(currentWeight[0].replace("\n", ""));
                int expectedWeight = 50 * 51 / 2 * Integer.parseInt(weightField.getText());
                int diff = (expectedWeight - w) * Integer.parseInt(weightField.getText());

                Text cw = new Text((expectedWeight - diff)+ " KG");
                cw.setFont(font2);
                cw.setLayoutX(230);
                cw.setLayoutY(425);
                pane.getChildren().add(cw);
            } else if (key == 13) {
                key++;
                int w = Integer.parseInt(currentWeight[0].replace("\n", ""));
                int expectedWeight = 50 * 51 / 2 * Integer.parseInt(weightField.getText());
                int diff = (expectedWeight - w) * Integer.parseInt(weightField.getText());
                int defIdx = diff / Integer.parseInt(weightField.getText());
                Text text1 = new Text("We expected to find " + expectedWeight +  " KG but we found " + (expectedWeight - diff) +
                        "\n,so difference is " + diff + "\n Defected box index = diff / weight = " + defIdx);
                text1.setFont(font2);
                text1.setLayoutX(45);
                text1.setLayoutY(100);
                pane.getChildren().add(text1);
            }
        });
        primaryStage.getIcons().add(new Image("images/box.png"));
        primaryStage.setTitle("Task 8");
    }
}