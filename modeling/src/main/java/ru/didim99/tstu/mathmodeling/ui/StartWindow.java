package ru.didim99.tstu.mathmodeling.ui;

import javax.swing.*;
import org.jzy3d.analysis.AnalysisLauncher;
import ru.didim99.tstu.mathmodeling.core.Functions;
import ru.didim99.tstu.mathmodeling.core.Processor;
import ru.didim99.tstu.mathmodeling.core.integrator.LayerIntegrator;
import ru.didim99.tstu.mathmodeling.core.integrator.SequenceIntegrator;

public class StartWindow extends JFrame {
  private JPanel rootPanel;
  private JCheckBox cbUseSurface;
  private JCheckBox cbWireFrame;
  private JButton btnLab4;
  private JButton btnLab5;

  public StartWindow() {
    setContentPane(rootPanel);
    setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
    setTitle(R.START_WINDOW_TITLE);
    initializeComponents();

    pack();
    setResizable(false);
    setLocation(R.START_WL);
    setVisible(true);
  }

  private void initializeComponents() {
    cbUseSurface.addActionListener(e ->
      cbWireFrame.setEnabled(cbUseSurface.isSelected()));
    btnLab4.addActionListener(e -> startAnalyzer(R.ID_LAB_4));
    btnLab5.addActionListener(e -> startAnalyzer(R.ID_LAB_5));
  }

  private void startAnalyzer(int id) {
    boolean surface = cbUseSurface.isSelected();
    boolean wireFrame = cbWireFrame.isSelected();
    Processor processor = null;

    switch (id) {
      case R.ID_LAB_4:
        processor = new Processor(new SequenceIntegrator(
          Functions.sequence, Functions.dT), Functions.liquidMapper);
        break;
      case R.ID_LAB_5:
        processor = new Processor(new LayerIntegrator(Functions.dirX,
          Functions.dirTau, Functions.mm), Functions.thermalMapper);
        break;
    }

    try {
      GraphUI ui = new GraphUI(surface, wireFrame, processor);
      AnalysisLauncher.open(ui, R.GRAPH_WB);
    } catch (Exception e) {
      e.printStackTrace();
    }
  }

  public static void main(String[] args) {
    new StartWindow();
  }
}
