template <typename T>
T sum(T tab, int size) {
	T suma = 0;
	for (int i = 0; i < size; i++) {
		suma += tab[i];
	}
	return suma;
}