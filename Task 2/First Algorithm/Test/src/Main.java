import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.layout.GridPane;
import javafx.scene.paint.Color;
import javafx.scene.shape.Rectangle;
import javafx.stage.Stage;


import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main extends Application {
    private static final int STARTX = 5;
    private static final int STARTY = 2;
    private int counter = 0;

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

    public static int[][] getCells(String board) {
        int[][] result = new int[8][8];

        String[] rows = board.split("\n");

        for (int i = 0; i < rows.length; i++) {
            String[] cells = rows[i].split(",");
            for (int j = 0; j < cells.length; j++) {
                result[i][j] = Integer.parseInt(cells[j].trim());
            }
        }

        return result;
    }

    public static void main(String[] args) {
        launch();
    }

    public static int getCellX(int move, int[][] moves) {
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (moves[i][j] == move) {
                    return i;
                }
            }
        }
        return -1;
    }

    public static int getCellY(int move, int[][] moves) {
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (moves[i][j] == move) {
                    return j;
                }
            }
        }
        return -1;
    }

    @Override
    public void start(Stage primaryStage) throws Exception {
        GridPane gridPane = new GridPane();
        Rectangle[][] squares = new Rectangle[8][8];

        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                squares[i][j] = new Rectangle(50, 50);
                squares[i][j].setFill((i + j) % 2 == 0 ? Color.WHITE : Color.SADDLEBROWN.brighter());
                gridPane.add(squares[i][j], i, j);
            }
        }

        Scene scene = new Scene(gridPane, 8 * 50, 8 * 50);
        primaryStage.setScene(scene);
        primaryStage.setTitle("Chessboard");
        primaryStage.show();

        Image knight = new Image("knight.png");
        Image knight2 = new Image("blackKnight.png");
        ImageView knightIcon = new ImageView(knight2);

        knightIcon.setFitHeight(50);
        knightIcon.setFitWidth(50);
        primaryStage.getIcons().add(knight);

        int[][] moves = getCells(execute(STARTX, STARTY));
        gridPane.add(knightIcon, STARTX, STARTY);
        squares[STARTX][STARTY].setFill(Color.RED);

        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                System.out.print(moves[i][j] + " ");
                if (moves[i][j] < 10) {
                    System.out.print(" ");
                }

            }
            System.out.println();
        }

        scene.setOnKeyPressed(e -> {
            if (counter == 63) {
                gridPane.getChildren().remove(knightIcon);
                gridPane.add(knightIcon, STARTX, STARTY);
            } else {
                int x = getCellX(counter, moves);
                int y = getCellY(counter, moves);
                gridPane.getChildren().remove(knightIcon);
                counter++;
                squares[x][y].setFill((x + y) % 2 == 0 ? Color.GREEN.brighter() : Color.GREEN.darker());
                x = getCellX(counter, moves);
                y = getCellY(counter, moves);
                squares[x][y].setFill((x + y) % 2 == 0 ? Color.SKYBLUE.brighter() : Color.SKYBLUE.darker());
                gridPane.add(knightIcon, x, y);
            }
        });
    }
}