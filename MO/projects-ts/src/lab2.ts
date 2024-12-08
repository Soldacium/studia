//import { createCanvas } from 'canvas';

const a = -1.37;
const b = -3.15;
const c = -3.82;
const r1 = -0.63;
const r2 = 3.82;
const r3 = -1.89;
const r4 = -4.22;

// Macierz A i wektor b
const A = [
  [20, a, b, c],
  [a, 20, a, b],
  [b, a, 20, a],
  [c, b, a, 20],
];
const bVec = [r1, r2, r3, r4];

// Funkcja do dekompozycji LU bez pivotingu
const luDecomposition = (A: number[][]) => {
  const n = A.length;
  const L = Array.from({ length: n }, () => Array(n).fill(0));
  const U = Array.from({ length: n }, () => Array(n).fill(0));

  for (let i = 0; i < n; i++) {
    for (let k = i; k < n; k++) {
      let sum = 0;
      for (let j = 0; j < i; j++) sum += L[i][j] * U[j][k];
      U[i][k] = A[i][k] - sum;
    }
    for (let k = i; k < n; k++) {
      if (i === k) L[i][i] = 1;
      else {
        let sum = 0;
        for (let j = 0; j < i; j++) sum += L[k][j] * U[j][i];
        L[k][i] = (A[k][i] - sum) / U[i][i];
      }
    }
  }
  return { L, U };
};

// Funkcja do eliminacji wprzód
const forwardElimination = (L: number[][], b: number[]) => {
  const n = b.length;
  const y = Array(n).fill(0);

  for (let i = 0; i < n; i++) {
    y[i] = b[i];
    for (let j = 0; j < i; j++) {
      y[i] -= L[i][j] * y[j];
    }
    y[i] /= L[i][i];
  }
  return y;
};

// Funkcja do podstawiania wstecz
const backwardSubstitution = (U: number[][], y: number[]) => {
  const n = y.length;
  const x = Array(n).fill(0);

  for (let i = n - 1; i >= 0; i--) {
    x[i] = y[i];
    for (let j = i + 1; j < n; j++) {
      x[i] -= U[i][j] * x[j];
    }
    x[i] /= U[i][i];
  }
  return x;
};

// Rozwiązanie układu równań przy użyciu dekompozycji LU
const solveLU = (A: number[][], b: number[]) => {
  const { L, U } = luDecomposition(A);
  const y = forwardElimination(L, b);
  const x = backwardSubstitution(U, y);
  return { L, U, x };
};

const { L, U, x } = solveLU(A, bVec);
console.log("Macierz L:", L);
console.log("Macierz U:", U);
console.log("Rozwiązanie x:", x);

// Weryfikacja rozwiązania
const verifySolution = (A: number[][], x: number[], b: number[]) => {
  const n = b.length;
  const Ax = Array(n).fill(0);

  for (let i = 0; i < n; i++) {
    for (let j = 0; j < n; j++) {
      Ax[i] += A[i][j] * x[j];
    }
  }

  return Ax.map((val, i) => val - b[i]);
};

const residual = verifySolution(A, x, bVec);
console.log("Weryfikacja (residua):", residual);

// Metoda iteracyjna Jacobiego
const jacobi = (A: number[][], b: number[], tol: number, maxIter: number) => {
  const n = b.length;
  let x = Array(n).fill(0);
  const xNew = Array(n).fill(0);
  const residuals: number[] = [];

  for (let k = 0; k < maxIter; k++) {
    for (let i = 0; i < n; i++) {
      let sum = 0;
      for (let j = 0; j < n; j++) {
        if (i !== j) sum += A[i][j] * x[j];
      }
      xNew[i] = (b[i] - sum) / A[i][i];
    }
    const norm = Math.max(...xNew.map((val, i) => Math.abs(val - x[i])));
    residuals.push(norm);
    if (norm < tol) break;
    x = [...xNew];
  }

  return { x, residuals };
};

// Metoda iteracyjna Gaussa-Seidela
const gaussSeidel = (
  A: number[][],
  b: number[],
  tol: number,
  maxIter: number
) => {
  const n = b.length;
  let x = Array(n).fill(0);
  const residuals: number[] = [];

  for (let k = 0; k < maxIter; k++) {
    const xOld = [...x];
    for (let i = 0; i < n; i++) {
      let sum = 0;
      for (let j = 0; j < n; j++) {
        if (i !== j) sum += A[i][j] * x[j];
      }
      x[i] = (b[i] - sum) / A[i][i];
    }
    const norm = Math.max(...x.map((val, i) => Math.abs(val - xOld[i])));
    residuals.push(norm);
    if (norm < tol) break;
  }

  return { x, residuals };
};

const tol = 1e-7;
const maxIter = 1000;

const resultJacobi = jacobi(A, bVec, tol, maxIter);
console.log("Rozwiązanie metodą Jacobiego:", resultJacobi.x);

const resultGaussSeidel = gaussSeidel(A, bVec, tol, maxIter);
console.log("Rozwiązanie metodą Gaussa-Seidela:", resultGaussSeidel.x);

// Wykres zbieżności
/*
const canvas = createCanvas(800, 600);
const ctx = canvas.getContext("2d");
ctx.fillStyle = "white";
ctx.fillRect(0, 0, canvas.width, canvas.height);
ctx.strokeStyle = "black";
ctx.lineWidth = 1;

const plotConvergence = (values: number[], color: string, method: string) => {
  ctx.strokeStyle = color;
  ctx.beginPath();
  for (let i = 0; i < values.length; i++) {
    const x = (i / values.length) * canvas.width;
    const y =
      canvas.height -
      (Math.log10(values[i]) / Math.log10(values[0])) * canvas.height;
    if (i === 0) {
      ctx.moveTo(x, y);
    } else {
      ctx.lineTo(x, y);
    }
  }
  ctx.stroke();
  ctx.fillStyle = color;
  ctx.fillText(method, 10, 10 + 20 * (method === "Jacobi" ? 0 : 1));
};

plotConvergence(resultJacobi.residuals, "red", "Jacobi");
plotConvergence(resultGaussSeidel.residuals, "blue", "Gauss-Seidel");
*/
