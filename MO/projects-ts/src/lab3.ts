const f = (x: number): number => Math.cos(x);

// Given values
const x = 2.26;
const a = 1.13;
const N = 10;
const q = 0.42;
const r = -0.26;
const s = 2.78;

// Step sizes
const hValues = [0.1, 0.05, 0.025, 0.0125];

// True derivatives for comparison
const trueFPrime = -Math.sin(x);
const trueFDoublePrime = -Math.cos(x);

// Finite difference methods
const finiteDifference = (
  f: (x: number) => number,
  x: number,
  h: number,
  method: string
): number => {
  if (method === "backward") {
    return (f(x) - f(x - h)) / h;
  } else if (method === "central") {
    return (f(x + h) - f(x - h)) / (2 * h);
  } else if (method === "central_second") {
    return (f(x + h) - 2 * f(x) + f(x - h)) / (h * h);
  }
  return 0;
};

// Calculate errors for each method and step size
const errorsBackward: number[] = [];
const errorsCentral: number[] = [];
const errorsCentralSecond: number[] = [];

hValues.forEach((h) => {
  const errorB = Math.abs(finiteDifference(f, x, h, "backward") - trueFPrime);
  const errorC = Math.abs(finiteDifference(f, x, h, "central") - trueFPrime);
  const errorC2 = Math.abs(
    finiteDifference(f, x, h, "central_second") - trueFDoublePrime
  );
  errorsBackward.push(errorB);
  errorsCentral.push(errorC);
  errorsCentralSecond.push(errorC2);
});

// Calculate the slopes (orders of accuracy)
const slope = (errors: number[]): number => {
  const logH = hValues.map((h) => Math.log10(h));
  const logErrors = errors.map((error) => Math.log10(error));
  const n = logH.length;
  const sumH = logH.reduce((a, b) => a + b, 0);
  const sumErrors = logErrors.reduce((a, b) => a + b, 0);
  const sumHH = logH.reduce((a, b) => a + b * b, 0);
  const sumHE = logH.reduce((sum, h, i) => sum + h * logErrors[i], 0);
  return (n * sumHE - sumH * sumErrors) / (n * sumHH - Math.pow(sumH, 2));
};

const slopeBackward = slope(errorsBackward);
const slopeCentral = slope(errorsCentral);
const slopeCentralSecond = slope(errorsCentralSecond);

console.log("Slope (Backward Difference):", slopeBackward);
console.log("Slope (Central Difference):", slopeCentral);
console.log("Slope (Central Second Difference):", slopeCentralSecond);

// Additional functions to solve the differential equations (exercise 2 and 3)

// Exercise 2: Solve the initial value problem using the modified Euler's method
const solveEuler = (a: number, N: number, steps: number[]): void => {
  steps.forEach((N) => {
    const dt = 2 / N;
    let y = 0;
    const results = [{ t: 0, y }];
    for (let i = 1; i <= N; i++) {
      const t = i * dt;
      y = (y + dt * Math.sin(Math.PI * t)) / (1 + a * dt);
      results.push({ t, y });
    }
    console.log(`Results for N = ${N}:`, results);
  });
};

// Exercise 3: Solve the second-order differential equation using finite differences
const solveSecondOrderDE = (
  q: number,
  r: number,
  s: number,
  N: number
): void => {
  const h = 5 / N;
  const A = Array.from({ length: N + 1 }, () => Array(N + 1).fill(0));
  const b = Array(N + 1).fill(0);
  const y = Array(N + 1).fill(0);

  A[0][0] = 1;
  A[N][N] = 1;

  for (let i = 1; i < N; i++) {
    A[i][i - 1] = 1 / (h * h) - q / (2 * h);
    A[i][i] = r - 2 / (h * h);
    A[i][i + 1] = 1 / (h * h) + q / (2 * h);
    b[i] = s;
  }

  // Gaussian elimination
  for (let i = 0; i <= N; i++) {
    const pivot = A[i][i];
    for (let j = i; j <= N; j++) {
      A[i][j] /= pivot;
    }
    b[i] /= pivot;
    for (let k = i + 1; k <= N; k++) {
      const factor = A[k][i];
      for (let j = i; j <= N; j++) {
        A[k][j] -= factor * A[i][j];
      }
      b[k] -= factor * b[i];
    }
  }

  for (let i = N; i >= 0; i--) {
    y[i] = b[i];
    for (let j = i + 1; j <= N; j++) {
      y[i] -= A[i][j] * y[j];
    }
  }

  console.log(`Results for N = ${N}:`, y);
};

solveSecondOrderDE(q, r, s, N);
solveSecondOrderDE(q, r, s, 2 * N);
solveSecondOrderDE(q, r, s, 4 * N);

const solutionLab3 = () => {
  console.log("Slope (Backward Difference):", slopeBackward);
  console.log("Slope (Central Difference):", slopeCentral);
  console.log("Slope (Central Second Difference):", slopeCentralSecond);
  solveEuler(a, N, [N, 2 * N, 4 * N]);
  solveSecondOrderDE(q, r, s, N);
  solveSecondOrderDE(q, r, s, 2 * N);
  solveSecondOrderDE(q, r, s, 4 * N);
};

export default solutionLab3;
