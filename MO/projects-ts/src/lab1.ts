// Params
const i = 4;
const j = 9;
const x0 = 5.71;
const y0 = 6.12;
const x1 = 0.34;
const y1 = 0.79;
const x2 = -1.12;
const y2 = 1.15;

const f1 = (x: number): number => Math.asin(x);
const f2 = (x: number): number => Math.pow(x, 3);

const f = (x: number): number => f1(x) * f2(x);

const df = (x: number): number =>
  3 * Math.pow(x, 2) * Math.asin(x) + Math.pow(x, 3) / Math.sqrt(1 - x * x);

// Bisection
const bisection = (
  f: (x: number) => number,
  a: number,
  b: number,
  tol: number,
  maxIter: number
): number => {
  let mid = a;
  for (let i = 0; i < maxIter; i++) {
    mid = (a + b) / 2;
    if (f(mid) === 0 || (b - a) / 2 < tol) {
      break;
    }
    if (f(mid) * f(a) > 0) {
      a = mid;
    } else {
      b = mid;
    }
  }
  return mid;
};

// Secant
const secant = (
  f: (x: number) => number,
  x0: number,
  x1: number,
  tol: number,
  maxIter: number
): number => {
  for (let i = 0; i < maxIter; i++) {
    const fx0 = f(x0);
    const fx1 = f(x1);
    const x2 = x1 - (fx1 * (x1 - x0)) / (fx1 - fx0);
    if (Math.abs(x2 - x1) < tol) {
      return x2;
    }
    x0 = x1;
    x1 = x2;
  }
  return x1;
};

// Newton
const newton = (
  f: (x: number) => number,
  df: (x: number) => number,
  x0: number,
  tol: number,
  maxIter: number
): number => {
  let x = x0;
  for (let i = 0; i < maxIter; i++) {
    const fx = f(x);
    const dfx = df(x);
    const x1 = x - fx / dfx;
    if (Math.abs(x1 - x) < tol) {
      return x1;
    }
    x = x1;
  }
  return x;
};

// Zad 1
const tol = 1e-10;
const maxIter = 1000;
const a = 0; // Interval start
const b = 1; // Interval end

const rootBisection = bisection(f, a, b, tol, maxIter);
console.log("Bisection method:", rootBisection);

const rootSecant = secant(f, x0, y0, tol, maxIter);
console.log("Secant method:", rootSecant);

const rootNewton = newton(f, df, x0, tol, maxIter);
console.log("Newton method:", rootNewton);

// Zad 2
const fSystem = (x: number, y: number): number =>
  Math.pow(x - x1, 2) + Math.pow(y - y1, 2) - 1;
const gSystem = (x: number, y: number): number =>
  Math.pow(x - x2, 2) + Math.pow(y - y2, 2) - 1;

const dfdx = (x: number, y: number): number => 2 * (x - x1);
const dfdy = (x: number, y: number): number => 2 * (y - y1);
const dgdx = (x: number, y: number): number => 2 * (x - x2);
const dgdy = (x: number, y: number): number => 2 * (y - y2);

const solveSystem = (
  x0: number,
  y0: number,
  tol: number,
  maxIter: number
): [number, number] => {
  let x = x0;
  let y = y0;
  for (let i = 0; i < maxIter; i++) {
    const fVal = fSystem(x, y);
    const gVal = gSystem(x, y);
    const jacobian = [
      [dfdx(x, y), dfdy(x, y)],
      [dgdx(x, y), dgdy(x, y)],
    ];
    const det =
      jacobian[0][0] * jacobian[1][1] - jacobian[0][1] * jacobian[1][0];
    const invJacobian = [
      [jacobian[1][1] / det, -jacobian[0][1] / det],
      [-jacobian[1][0] / det, jacobian[0][0] / det],
    ];
    const dx = invJacobian[0][0] * fVal + invJacobian[0][1] * gVal;
    const dy = invJacobian[1][0] * fVal + invJacobian[1][1] * gVal;
    x -= dx;
    y -= dy;
    if (Math.sqrt(dx * dx + dy * dy) < tol) {
      break;
    }
  }
  return [x, y];
};

const [solutionX, solutionY] = solveSystem(x0, y0, tol, maxIter);
console.log("Solution for system of equations:", solutionX, solutionY);
