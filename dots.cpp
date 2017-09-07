#include <iostream>
#include <vector>

using namespace std;

// Точка (координаты)
struct Point
{
	float x, y;
};

// Окружность (координаты цента и радиус)
struct Cicle
{
	float x, y, R;
};

// Функция, проверяющая, в окружности ли точка
bool is_point_in_cicle(Point p, Cicle c);

int main()
{
	// Массив точек
	vector<Point> points;
	// Массив окружностей
	vector<Cicle> cicles;
	size_t N, M; // Количество точек и окружностей

	cout << "Введите количество точек: ";
	cin >> N;
	cout << "Введите количество окружностей: ";
	cin >> M;

	// Ввод точек
	cout << "Введите координаты " << N << " точек в формате: 'x y'" << endl;
	for(size_t i = 0; i < N; i++) {
		Point p;
		cin >> p.x >> p.y;
		points.push_back(p);
	}

	// Ввод окружностей
	cout << "Введите координаты и радиусы " << M << " окружностей в формате: 'x y R'" << endl;
	for(size_t i = 0; i < M; i++) {
		Cicle c;
		cin >> c.x >> c.y >> c.R;
		cicles.push_back(c);
	}

	// Матрица вхождений точек в окружности
	bool matrix[M][N];

	// Количество точек в каждой окружности
	size_t points_counter[M];
	for(size_t i = 0; i < M; i++) {
		points_counter[i] = 0;
		for(size_t j = 0; j < N; j++) {
			bool in_cicle = is_point_in_cicle(points[j], cicles[i]);
			if(in_cicle) points_counter[i]++;
			matrix[i][j] = in_cicle;
		}
	}

	// Вывод матрицы на экран
	cout << "Матрица вхождения точек в окружности (по столбцам - точки, по строкам - окружности)" << endl;
	for(size_t i = 0; i < M; i++) {
		for(size_t j = 0; j < N; j++) {
			cout << matrix[i][j] << ' ';
		}
		cout << endl;
	}

	// Вывод количества точек в каждой окружности
	cout << "В окружностях точек:" << endl;
	for(size_t i = 0; i < M; i++) {
		cout << points_counter[i] << ' ';
	}
	cout << endl;

	// Максимальное количество точек в окружности
	size_t max_points = points_counter[0];

	// Индекс окружности, содержащей больше всего точек
	size_t max_cicle = 0;

	for(size_t i = 1; i < M; i++) {
		if(points_counter[i] > max_points) {
			max_points = points_counter[i];
			max_cicle = i;
		}
	}

	cout << "Больше всего точек в " << max_cicle + 1 << " окружности: " << max_points << endl;

	return 0;
}

// Функция, проверяющая, в окружности ли точка
bool is_point_in_cicle(Point p, Cicle c)
{
	return (p.x - c.x)*(p.x - c.x) + (p.y - c.y)*(p.y - c.y) <= c.R*c.R;
}
