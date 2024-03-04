import javafx.animation.TranslateTransition;
import javafx.scene.Node;
import javafx.scene.image.ImageView;
import javafx.scene.layout.Pane;
import javafx.scene.paint.Color;
import javafx.scene.text.Font;
import javafx.scene.text.Text;
import javafx.util.Duration;

public class Box {
    private static final String BOX_PNG = "images/box.png";
    private static final String BALL_PNG = "images/ball.png";
    private int id;
    private int xOffset;
    private int yOffset;
    private Text number;
    private ImageView imageView;
    private ImageView[] ball = new ImageView[5];

    public Box(int id, int xOffset, int yOffset) {
        this.id = id;
        this.xOffset = xOffset;
        this.yOffset = yOffset;

        imageView = new ImageView(BOX_PNG);
        imageView.setLayoutX(xOffset - 250);
        imageView.setLayoutY(yOffset - 200);
        imageView.setScaleX(0.4);
        imageView.setScaleY(0.4);

        for (int i = 0; i <= id; i++) {
            ball[i] = new ImageView(BALL_PNG);
            ball[i].setScaleX(0.1);
            ball[i].setScaleY(0.1);
            ball[i].setLayoutX(-70 + i * 5);
            ball[i].setLayoutY(-70 + i * 5);
        }

        number = new Text(String.valueOf(id));
        number.setFill(Color.RED);
        number.setFont(new Font(24));
        number.setLayoutX(xOffset + 55);
        number.setLayoutY(yOffset + 40);
    }

    public void removeBox(Pane pane) {
        pane.getChildren().remove(imageView);
        pane.getChildren().remove(number);
    }

    public Node[] getBox() {
        Node[] box = {imageView, number};
        return box;
    }

    public void enterScene() {
        TranslateTransition translateTransition = new TranslateTransition(Duration.seconds(2), imageView);
        TranslateTransition translateTransition2 = new TranslateTransition(Duration.seconds(2), number);
        translateTransition.setToX(150);
        translateTransition.setToY(150);
        translateTransition2.setToX(160);
        translateTransition2.setToY(145);
        translateTransition.setAutoReverse(false);
        translateTransition2.setAutoReverse(false);
        translateTransition.play();
        translateTransition2.play();
    }

    public void leaveScene(Pane pane) {
        TranslateTransition translateTransition = new TranslateTransition(Duration.seconds(2), imageView);
        TranslateTransition translateTransition2 = new TranslateTransition(Duration.seconds(2), number);
        translateTransition.setToX(1000);
        translateTransition.setToY(number.getLayoutY());
        translateTransition2.setToX(1000);
        translateTransition2.setToY(number.getLayoutY());
        translateTransition.setAutoReverse(false);
        translateTransition2.setAutoReverse(false);
        translateTransition.play();
        translateTransition2.play();

        translateTransition2.setOnFinished(e -> removeBox(pane));
    }

    public void getBalls(int x, int y, int idx, Pane pane) {
        pane.getChildren().add(ball[idx]);
        TranslateTransition translateTransition = new TranslateTransition(Duration.seconds(2), ball[idx]);
        translateTransition.setToX(x);
        translateTransition.setToY(y);
        translateTransition.setAutoReverse(false);
        translateTransition.play();
        translateTransition.setOnFinished(event -> pane.getChildren().remove(ball[idx]));
    }
}
