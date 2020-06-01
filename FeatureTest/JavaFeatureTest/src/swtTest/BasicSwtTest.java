package swtTest;

import org.eclipse.swt.SWT;
import org.eclipse.swt.events.MouseEvent;
import org.eclipse.swt.events.MouseListener;
import org.eclipse.swt.graphics.Color;
// import org.eclipse.swt.layout.FillLayout;
import org.eclipse.swt.layout.GridLayout;
import org.eclipse.swt.widgets.Button;
import org.eclipse.swt.widgets.Display;
import org.eclipse.swt.widgets.Label;
import org.eclipse.swt.widgets.MessageBox;
import org.eclipse.swt.widgets.Shell;
import org.eclipse.swt.widgets.Text;

public class BasicSwtTest {
    private Display login = new Display();
    private Shell basic_shell = new Shell(login);
    private Text user_name;
    private Text passwd;
    private Label user_name_hint;
    private Label passwd_hint;
    private Button confirm;
    private Button cancle;
    private Color gray = new Color(login, 160, 160, 160);
    private Color white = new Color(login, 255, 255, 255);

    BasicSwtTest() {
        basic_shell.setBounds(0, 0, 300, 150);
        // basic_shell.setLayout(new FillLayout());
        GridLayout layout = new GridLayout();
        layout.numColumns = 2;
        basic_shell.setLayout(layout);
        user_name_hint = new Label(basic_shell, SWT.CENTER);
        user_name = new Text(basic_shell, SWT.CENTER);
        passwd_hint = new Label(basic_shell, SWT.CENTER);
        passwd = new Text(basic_shell, SWT.CENTER);
        confirm = new Button(basic_shell, SWT.CENTER);
        cancle = new Button(basic_shell, SWT.CENTER);
        user_name_hint.setText("用户名");
        passwd_hint.setText("密码");
        confirm.setText("确认");
        cancle.setText("取消");
        cancle.addMouseListener(new MouseListener() {

            @Override
            public void mouseUp(MouseEvent arg0) {
            }

            @Override
            public void mouseDown(MouseEvent arg0) {
                login.dispose();
            }

            @Override
            public void mouseDoubleClick(MouseEvent arg0) {
            }
        });
        confirm.addMouseListener(new MouseListener() {

            @Override
            public void mouseUp(MouseEvent arg0) {
            }

            @Override
            public void mouseDown(MouseEvent arg0) {
                if (user_name.getText().compareTo(passwd.getText()) != 0) {
                    passwd.setText("");
                    MessageBox msb = new MessageBox(basic_shell, SWT.RETRY);
                    msb.setText("Warning");
                    msb.setMessage("Wrong Passwd");
                    msb.open();
                } else {
                    login.dispose();
                }
            }

            @Override
            public void mouseDoubleClick(MouseEvent arg0) {
            }
        });
        user_name_hint.setBackground(gray);
        passwd_hint.setBackground(gray);
        user_name.setBackground(gray);
        passwd.setBackground(gray);
        basic_shell.setForeground(white);
    }

    public void test() {
        basic_shell.open();
        basic_shell.setText("Login");
        while (!basic_shell.isDisposed()) {
            if (!login.readAndDispatch()) {
                login.sleep();
            }
        }
        login.dispose();
    }

    public static void main(String[] args) {
        new BasicSwtTest().test();
    }

}