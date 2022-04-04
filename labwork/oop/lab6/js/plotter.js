class Plotter {
  constructor(canvas, gridColor) {
    this.gridColor = gridColor;
    this.realWidth = canvas.width;
    this.realHeight = canvas.height;
    this.ctx = canvas.getContext("2d");
    this.setViewRange(-10, 10, -10, 10);
    this.ctx.strokeStyle = "#ffffff";
    this.ctx.fillStyle = "#ffffff";

    this.plotSteps = 100;
    this.plotThinkness = 1;
    this.gridThinkness = 1;
    this.gridScale = 1.0;
    this.gridDotSize = 5;
  }

  setViewRange(xMin, xMax, yMin, yMax) {
    this.xMin = xMin;
    this.xMax = xMax;
    this.yMin = yMin;
    this.yMax = yMax;
    this.xFactor = this.realWidth / (this.xMax - this.xMin);
    this.yFactor = this.realHeight / (this.yMax - this.yMin);
  }

  setGridScale(gridScale) {
    this.gridScale = gridScale;
  }

  clear() {
    this.ctx.clearRect(0, 0, this.realWidth, this.realHeight);
  }

  drawGrid() {
    this.ctx.fillStyle = this.gridColor;
    this.ctx.strokeStyle = this.gridColor;
    this.ctx.lineWidth = this.gridThinkness;

    this.ctx.beginPath();
    this.ctx.moveTo(this.x(this.xMin), this.y(0));
    this.ctx.lineTo(this.x(this.xMax), this.y(0));
    this.ctx.moveTo(this.x(0), this.y(this.yMin));
    this.ctx.lineTo(this.x(0), this.y(this.yMax));

    this.ctx.textAlign = "start";
    var dots = (this.xMax - this.xMin) / this.gridScale;
    for (var i = 0; i <= dots; i++) {
      var x = this.xMin + this.gridScale * i;
      this.ctx.moveTo(this.x(x), this.y(0) - this.gridDotSize);
      this.ctx.lineTo(this.x(x), this.y(0) + this.gridDotSize);
      if (x !== 0 && x % 1 === 0)
        this.ctx.fillText(`${x.toFixed(1)}`, this.x(x), this.y(0) + 20);
    }

    this.ctx.textAlign = "end";
    dots = (this.yMax - this.yMin) / this.gridScale;
    for (var i = 0; i <= dots; i++) {
      var y = this.yMin + this.gridScale * i;
      this.ctx.moveTo(this.x(0) - this.gridDotSize, this.y(y));
      this.ctx.lineTo(this.x(0) + this.gridDotSize, this.y(y));
      if (y !== 0 && y % 1 === 0)
        this.ctx.fillText(`${y.toFixed(1)}`, this.x(0) - 10, this.y(y));
    }

    this.ctx.closePath();
    this.ctx.stroke();
  }

  drawLegend(legend) {
    this.ctx.textAlign = "end";
    this.ctx.fillStyle = this.gridColor;
    var y = this.yRaw(this.realHeight - 20);

    for (var key in legend) {
      var item = legend[key];
      this.ctx.strokeStyle = item[1];
      this.ctx.beginPath();
      this.ctx.moveTo(this.realWidth - 55, y - 4);
      this.ctx.lineTo(this.realWidth - 10, y - 4);
      this.ctx.moveTo(this.realWidth - 10, y - 4);
      this.ctx.closePath();
      this.ctx.stroke();
      this.ctx.fillText(item[0], this.realWidth - 60, y);
      y += 15;
    }
  }

  drawFunction(func, plotColor, xMin, xMax) {
    if (xMin === undefined) xMin = this.xMin;
    if (xMax === undefined) xMax = this.xMax;
    var xStep = (xMax - xMin) / this.plotSteps;
    var x = xMin;

    this.ctx.strokeStyle = plotColor;
    this.ctx.lineWidth = this.plotThinkness;

    this.ctx.beginPath();
    this.ctx.moveTo(this.x(xMin), this.y(func(xMin)));

    while (x <= xMax) {
      this.ctx.lineTo(this.x(x), this.y(func(x)));
      x += xStep;
    }

    this.ctx.lineTo(this.x(xMax), this.y(func(xMax)));
    this.ctx.moveTo(this.x(xMax), this.y(func(xMax)));
    this.ctx.closePath();
    this.ctx.stroke();
  }

  animateFunction(func, plotColor, xMin, xMax) {
    if (xMin === undefined) xMin = this.xMin;
    if (xMax === undefined) xMax = this.xMax;
    var xStep = (xMax - xMin) / this.plotSteps;
    
    this.ctx.lineWidth = this.plotThinkness;

    var drawer = new AnimatedDrawer(this, plotColor, func, xMin, xMax, xStep);
    return drawer.start();
  }

  x(x) {
    return (x - this.xMin) * this.xFactor;
  }

  y(y) {
    y = (y - this.yMin) * this.yFactor;
    return this.realHeight - y;
  }

  yRaw(y) {
    return this.realHeight - y;
  }
}

class AnimatedDrawer {
  constructor(plotter, plotColor, func, xMin, xMax, xStep) {
    this.plotColor = plotColor;
    this.plotter = plotter;
    this.func = func;
    this.xMin = xMin;
    this.xMax = xMax;
    this.xStep = xStep;

    this.framerate = 25;
  }

  start() {
    var ctx = this.plotter.ctx;
    var xMin = this.xMin;
    this.x = xMin;
    this.timerId = setInterval(this.drawFrame, 1000 / this.framerate, this);
    return this.timerId;
  }

  drawFrame(drawer) {
    var plotter = drawer.plotter;
    var x = drawer.x;

    if (x < drawer.xMax) {
      plotter.ctx.beginPath();
      plotter.ctx.moveTo(plotter.x(x), plotter.y(drawer.func(x)));
      x += drawer.xStep;
      if (x > drawer.xMax) x = drawer.xMax;
      plotter.ctx.lineTo(plotter.x(x), plotter.y(drawer.func(x)));
      plotter.ctx.closePath();
      plotter.ctx.strokeStyle = drawer.plotColor;
      plotter.ctx.stroke();
    } else {
      clearInterval(drawer.timerId);
    }

    drawer.x = x;
  }
}