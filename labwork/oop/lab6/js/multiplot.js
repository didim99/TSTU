function include(url) {
  var script = document.createElement('script');
  script.src = url;
  document.getElementsByTagName('head')
    [0].appendChild(script);
}

include("plotter.js");
var start, plotter, running, id1, id2, id3;

function init() {
  start = document.getElementById('start');
  start.onclick = startHandler;
  var plot = document.getElementById('plot');
  plotter = new Plotter(plot, "#222");
  plotter.setViewRange(-0.25, 1.75, -0.5, 1.5);
  plotter.setGridScale(0.25);
  clearPlot();
  running = false;
}

function f(x) {
  return Math.cos(x);
}

function p1(x) {
  return 2 / Math.PI;
}

function p2(x) {
  return 4 / Math.PI * (1 - (2 * x / Math.PI));
}

function startHandler() {
  running = !running;
  if (running) {
    start.textContent = "Clear";
    id1 = plotter.animateFunction(f, "#44d", 0, Math.PI/2);
    id2 = plotter.animateFunction(p1, "#dd4", -0.26, 1.76);
    id3 = plotter.animateFunction(p2, "#d44", -0.26, 1.76);
  } else {
    start.textContent = "Plot";
    clearInterval(id1);
    clearInterval(id2);
    clearInterval(id3);
    clearPlot();
  }
}

function clearPlot() {
  plotter.clear();
  plotter.drawGrid();
  plotter.drawLegend([["g(x)", "#44d"], ["p1(x)", "#dd4"], ["p2(x)", "#d44"]]);
}
