package ru.didim99.tstu.networkauto;

import android.content.Intent;
import android.os.Bundle;
import androidx.appcompat.app.AppCompatActivity;

public class MainActivity extends AppCompatActivity {
  @Override
  protected void onCreate(Bundle savedInstanceState) {
    super.onCreate(savedInstanceState);
    setContentView(R.layout.activity_main);
    findViewById(R.id.btnChoice).setOnClickListener(v ->
      startActivity(new Intent(this, SecondActivity.class)));
  }
}
