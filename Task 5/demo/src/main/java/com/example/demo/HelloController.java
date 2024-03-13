package com.example.demo;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.fxml.Initializable;
import javafx.fxml.LoadException;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.input.ContextMenuEvent;
import javafx.scene.input.MouseEvent;
import javafx.scene.media.Media;
import javafx.scene.media.MediaPlayer;
import javafx.scene.media.MediaView;
import javafx.scene.text.Text;
import javafx.stage.Stage;

import java.io.File;
import java.net.URL;
import java.util.ResourceBundle;


public class HelloController implements Initializable{

    int input_data = 0;
    @FXML
    private Label alertText;

    @FXML
    private Button checkButton;

    @FXML
    private TextField inputData;

    @FXML
    private Button visualizationButton;

    @FXML
    private Text welcomeText;
    ////////////////////////////////////////////
    @FXML
    private MediaView mediaView;
    private File file;
    private Media media;
    private MediaPlayer mediaPlayer;

    @FXML
    void checkButtonHandler(MouseEvent event) {
        try
        {
            input_data = Integer.parseInt(inputData.getText());
            boolean conditionValue = check_possible(input_data);
            if (conditionValue == true)
            {
                alertText.setText("Possible !!");
            }
            else
            {
                alertText.setText("Impossible !!");
            }
        }
        catch (NumberFormatException e)
        {
            alertText.setText("Enter Numbers only !!");
        }
        catch (Exception e)
        {
            System.out.println(e);
        }

    }

    @FXML
    void visualizationButtonHandler(MouseEvent event) {
        try
        {

            input_data = Integer.parseInt(inputData.getText());
            if(input_data == 6)
            {
                alertText.setText("Possible to visualize");

            }
            else
            {
                alertText.setText("can't be visualize using available resources ");
            }
        }
        catch (NumberFormatException e)
        {
            alertText.setText("Enter Numbers only !!");
        }
        catch (Exception e)
        {
            System.out.println(e);
        }
    }



    @FXML
    void backButtonHandler(ActionEvent event) {

    }
    @Override
    public void initialize(URL url, ResourceBundle resourceBundle) {
        FXMLLoader fxmlLoader = new FXMLLoader(HelloApplication.class.getResource("visualzation_pane.fxml"));

    }
    static boolean check_possible(int n){
        if (n>0){
            // loop to 31 as higher numbers cannot be represented as int
            for (int i = 2; i<31; i++){
                if (n == (Math.pow(2,i))- 2) {
                    return true;
                }
            }
            return false;
        }
        else return false;
    }
}