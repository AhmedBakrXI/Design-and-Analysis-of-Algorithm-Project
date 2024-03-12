module com.example.designofalgorithmui {
    requires javafx.controls;
    requires javafx.fxml;
    requires java.desktop;

    opens com.example.designofalgorithmui to javafx.fxml;
    exports com.example.designofalgorithmui;
}