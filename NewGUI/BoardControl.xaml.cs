using System;
using System.Collections.Generic;
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

namespace NewGUI {
	[ContentProperty(nameof(Children))]
	public partial class BoardControl : UserControl {

		#region Obsługa potomków w .xaml
		public static readonly DependencyPropertyKey ChildrenProperty = DependencyProperty.RegisterReadOnly(nameof(Children), typeof(UIElementCollection), typeof(BoardControl), new PropertyMetadata());
		public UIElementCollection Children {
			get { return (UIElementCollection)GetValue(ChildrenProperty.DependencyProperty); }
			private set { SetValue(ChildrenProperty, value); }
		}
		#endregion

		#region pola
		private UIElement[ , ] grid = new UIElement[10,10];
		#endregion

		//konstruktor
		public BoardControl()
        {
            InitializeComponent();
			Children = BoardGrid.Children;
		}

		//dodaje statek na planszę
		public void addShip(Point point, int size, Direction direction) {
			if (grid[point.x, point.y] != null) {
				throw new ArgumentException(string.Format("Square already occupied"));
			}
			Rectangle ship = new Rectangle {
				Margin = new Thickness(5),
				Stroke = Brushes.Black,
				Fill = Brushes.Black,
				RadiusX = 30,
				RadiusY = 30
			};
			ship.SetValue(Grid.ColumnProperty, point.x + 1);
			ship.SetValue(Grid.RowProperty, point.y + 1);
			switch (direction) {
				case Direction.HORIZONTAL:
					ship.SetValue(Grid.ColumnSpanProperty, size);
					ship.SetValue(Grid.RowSpanProperty, 1);
					break;
				case Direction.VERTICAL:
					ship.SetValue(Grid.ColumnSpanProperty, 1);
					ship.SetValue(Grid.RowSpanProperty, size);
					break;
				default:
					throw new ArgumentException(string.Format("Invalid direction"));
			}
			grid[point.x, point.y] = ship;
			BoardGrid.Children.Add(ship);
		}

		//usuwa z planszy statek leżący na polu point
		public void removeShip(Point point) {
			BoardGrid.Children.Remove(grid[point.x, point.y]);
		}
    }
}
