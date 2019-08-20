using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Markup;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

using static NewGUI.Const;

namespace NewGUI.View {
	//[ContentProperty(nameof(Children))]
	public partial class BoardControl : UserControl {

		#region Obsługa potomków w .xaml
		/*public static readonly DependencyPropertyKey ChildrenProperty = DependencyProperty.RegisterReadOnly(nameof(Children), typeof(UIElementCollection), typeof(BoardControl), new PropertyMetadata());
		public UIElementCollection Children {
			get { return (UIElementCollection)GetValue(ChildrenProperty.DependencyProperty); }
			private set { SetValue(ChildrenProperty, value); }
		}*/
		#endregion

		#region pola
		List<Tuple<ShipInfo, UIElement>> list = new List<Tuple<ShipInfo, UIElement>>(); //statki na planszy
		Button[ , ] buttonTab = new Button[BOARDSIZE, BOARDSIZE];
		ShotMarkControl[ , ] stateTab = new ShotMarkControl[BOARDSIZE, BOARDSIZE];
		#endregion

		//konstruktor
		public BoardControl()
        {
            InitializeComponent();
			//Children = BoardGrid.Children;
			generateButtons();
		}

		#region statki
		//dodaje statek na planszę
		public void addShip(ShipInfo ship) {
			if (list.Exists(v => (v.Item1.point.x == ship.point.x && v.Item1.point.y == ship.point.y))) {
				throw new ArgumentException("Square already occupied");
			}
			Rectangle drawObj = new Rectangle {
				Margin = new Thickness(5),
				Stroke = Brushes.Black,
				Fill = Brushes.Black,
				RadiusX = 30,
				RadiusY = 30
			};
			drawObj.SetValue(Grid.ColumnProperty, ship.point.x + 1);
			drawObj.SetValue(Grid.RowProperty, ship.point.y + 1);
			drawObj.SetValue(Panel.ZIndexProperty, 0);
			switch (ship.direction) {
				case Direction.HORIZONTAL:
					drawObj.SetValue(Grid.ColumnSpanProperty, ship.size);
					drawObj.SetValue(Grid.RowSpanProperty, 1);
					break;
				case Direction.VERTICAL:
					drawObj.SetValue(Grid.ColumnSpanProperty, 1);
					drawObj.SetValue(Grid.RowSpanProperty, ship.size);
					break;
				default:
					throw new InvalidEnumArgumentException("Invalid direction");
			}
			Tuple<ShipInfo, UIElement> pair = new Tuple<ShipInfo, UIElement>(ship, drawObj);
			list.Add(pair);
			BoardGrid.Children.Add(drawObj);
		}
		public void addShip(int _size, Point _point, Direction _direction, bool _sunk = false) {
			ShipInfo ship = new ShipInfo {
				size = _size,
				point = _point,
				direction = _direction,
				sunk = _sunk
			};
			addShip(ship);
		}

		//usuwa z planszy statek 'ship'
		public void removeShip(ShipInfo ship) {
			List<Tuple<ShipInfo, UIElement>> removeList = list.FindAll(v => v.Item1.size == ship.size && v.Item1.point.x == ship.point.x && v.Item1.point.y == ship.point.y && v.Item1.direction == ship.direction);
			foreach (Tuple<ShipInfo, UIElement> k in removeList) {
				BoardGrid.Children.Remove(k.Item2);
				list.Remove(k);
			}
		}
		//usuwa z planszy statek leżący na polu 'point'
		public void removeShip(Point point) {
			Tuple<ShipInfo, UIElement> removeItem = list.Find(v => v.Item1.point.x == point.x && v.Item1.point.y == point.y);
			BoardGrid.Children.Remove(removeItem.Item2);
			list.Remove(removeItem);
		}

		//usuwa z planszy wszystkie statki
		public void clearShips() {
			foreach (Tuple<ShipInfo, UIElement> k in list) {
				BoardGrid.Children.Remove(k.Item2);
			}
			list.Clear();
		}
		#endregion

		#region stan pola
		public void setState(Point point, ShotResult newState) {
			stateTab[point.y, point.x] = new ShotMarkControl(newState);
			stateTab[point.y, point.x].SetValue(Grid.ColumnProperty, point.x + 1);
			stateTab[point.y, point.x].SetValue(Grid.RowProperty, point.y + 1);
			stateTab[point.y, point.x].SetValue(Panel.ZIndexProperty, 1);
			BoardGrid.Children.Add(stateTab[point.y, point.x]);
		}
		public void setState(int x, int y, ShotResult newState) {
			setState(new Point(x, y), newState);
		}
			#endregion

			#region przyciski
			//generuje niewidzialne przyciski na planszy wywołujące zdarzenie 'onClick'
			private void generateButtons() {
			for (int i = 0; i < BOARDSIZE; i++) {
				for (int j = 0; j < BOARDSIZE; j++) {
					Button button = new Button() {
						Opacity = 0
					};
					button.SetValue(Panel.ZIndexProperty, 2);
					button.SetValue(Grid.ColumnProperty, j + 1);
					button.SetValue(Grid.RowProperty, i + 1);
					buttonTab[i, j] = button;
				}
			}
		}

		//dodaje zdarzenie "onClick" do wszystkich przycisków
		public void subscribeButtons(RoutedEventHandler onClick) {
			foreach (var button in buttonTab) {
				button.IsEnabled = true;
				button.Click += onClick;
			}
		}
		//usuwa zdarzenie "onClick" z wszystkich przycisków
		public void unsubscribeButtons(RoutedEventHandler onClick) {
			foreach (var button in buttonTab) {
				button.Click -= onClick;
			}
		}
		#endregion
	}
}
