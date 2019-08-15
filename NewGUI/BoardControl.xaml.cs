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

	public static readonly DependencyPropertyKey ChildrenProperty = DependencyProperty.RegisterReadOnly(nameof(Children), typeof(UIElementCollection), typeof(BoardControl), new PropertyMetadata());

		public UIElementCollection Children {
			get { return (UIElementCollection)GetValue(ChildrenProperty.DependencyProperty); }
			private set { SetValue(ChildrenProperty, value); }
		}
		public BoardControl()
        {
            InitializeComponent();
			Children = BoardGrid.Children;
		}

		//dodaje statek na planszę
		public void addShip(Point point, int size, Direction direction) {
			Rectangle drawObj = new Rectangle {
				Margin = new Thickness(5),
				Stroke = Brushes.Black,
				Fill = Brushes.Black,
				RadiusX = 30,
				RadiusY = 30
			};
			drawObj.SetValue(Grid.ColumnProperty, point.x + 1);
			drawObj.SetValue(Grid.RowProperty, point.y + 1);
			switch (direction) {
				case Direction.HORIZONTAL:
					drawObj.SetValue(Grid.ColumnSpanProperty, size);
					drawObj.SetValue(Grid.RowSpanProperty, 1);
					break;
				case Direction.VERTICAL:
					drawObj.SetValue(Grid.ColumnSpanProperty, 1);
					drawObj.SetValue(Grid.RowSpanProperty, size);
					break;
				default:
					throw new ArgumentException(string.Format("Invalid direction"));
			}
			BoardGrid.Children.Add(drawObj);
		}
    }
}
