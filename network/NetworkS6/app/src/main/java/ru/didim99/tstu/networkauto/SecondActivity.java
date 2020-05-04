package ru.didim99.tstu.networkauto;

import android.os.Bundle;
import android.widget.TextView;
import androidx.appcompat.app.AppCompatActivity;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Locale;
import java.util.Random;

public class SecondActivity extends AppCompatActivity {


  @Override
  protected void onCreate(Bundle savedInstanceState) {
    super.onCreate(savedInstanceState);
    setContentView(R.layout.activity_second);
    TextView tvNumber = findViewById(R.id.tvNumber);
    TextView tvDate = findViewById(R.id.tvDate);
    TextView tvTime = findViewById(R.id.tvTime);

    Date date = new Date();
    Random random = new Random();
    tvNumber.setText(String.valueOf(random.nextInt(26)));
    SimpleDateFormat df = new SimpleDateFormat("dd.MM.yyyy", Locale.ROOT);
    SimpleDateFormat tf = new SimpleDateFormat("HH:mm", Locale.ROOT);
    tvDate.setText(df.format(date));
    tvTime.setText(tf.format(date));
  }
}
