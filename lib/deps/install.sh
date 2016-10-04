#!/bin/sh
clear
echo "## ----------------------------------------------------------------------------- ##"
sleep 0.03
echo "## -- EPITECH 2015-2042 ------------------- ---   -   --- ---- --  --   - --- -- ##"
sleep 0.03
echo "## ---Jason Brillante brilla_a brilla_b --- ---- --- - -- --- - - - -- --  -- -- ##"
sleep 0.03
echo "## ---Les Lapins Noirs -------------------- ---- --- - -- --- - - - -- --  -- -- ##"
sleep 0.03
echo "## ---------------------------------------- ---- --- - -- --- - - - -- --  -- -- ##"
sleep 0.03
echo "## -----|\-//------------------------------ ---- ---   -- --- - -  --- -- - - -- ##"
sleep 0.03
echo "## -----||//___---------------------------- ---- --- - -- ---   - ---- -- - - -- ##"
sleep 0.03
echo "## ----O  /    \--------------------------- ---- --- - -- --- - - ---- -- --  -- ##"
sleep 0.03
echo "## ---<________/---------------------------   -   -   ---   - - - ---   - --- -- ##"
sleep 0.03
echo "## ----------------------------------------------------------------------------- ##"
sleep 0.03
echo "## ----------------------------------------------------------------------------- ##"
sleep 0.03
echo "## ----------------------------------------------------------------------------- ##"
sleep 0.03
echo "## ----------------------------------------------------------------------------- ##"
sleep 0.03
echo "## ----------------------------------------------------------------------------- ##"
sleep 0.03
echo "## ----------------------------------------------------------------------------- ##"
echo "Targets are ~/.froot/include and ~/.froot/lib"

get_out()
{
    echo $1
    exit
}

test_and_add_bash()
{
    if [ -e $1 ] ; then
	echo "" >> $1
	echo "export LD_LIBRARY_PATH=\"${HOME}/.froot/lib/\"" >> $1
	echo "export C_INCLUDE_PATH=\"${HOME}/.froot/include/\"" >> $1
	echo "export CPLUS_INCLUDE_PATH=\"${HOME}/.froot/include/\"" >> $1
    fi
}

test_and_add_csh()
{
    if [ -e $1 ] ; then
	echo "" >> $1
	echo "setenv LD_LIBRARY_PATH \"${HOME}/.froot/lib/\"" >> $1
	echo "setenv C_INCLUDE_PATH \"${HOME}/.froot/include/\"" >> $1
	echo "setenv CPLUS_INCLUDE_PATH \"${HOME}/.froot/include/\"" >> $1
    fi
}


mkdir -p ~/.froot/lib ~/.froot/include	|| get_out "Failed to create installation directories."

cp -r lib/deps/lib/SFML ~/.froot/include/	|| get_out "Failed to install SFML headers."
cp -r lib/deps/include/*.h ~/.froot/include/	|| get_out "Failed to install Lapin headers."
cp -r lib/deps/include/lapin/ ~/.froot/include/	|| get_out "Failed to install Lapin headers."


cp -r lib/deps/liblapin.a lib/deps/lib/*.so* ~/.froot/lib	|| get_out "Failed to install SFML & Lapin binaries"

chmod 644 ~/.froot/include/*.h*		|| get_out "Failed to change mode of headers."
chmod 644 ~/.froot/include/*/*.h*	|| get_out "Failed to change mode of headers."
chmod 644 ~/.froot/lib/*.a		|| get_out "Failed to change mode of binaries."
chmod 755 ~/.froot/lib/*.so		|| get_out "Failed to change mode of binaries."


ln -fs ~/.froot/lib/libsfml-audio.so ~/.froot/lib/libsfml-audio.so.2.3 && \
    ln -fs ~/.froot/lib/libsfml-graphics.so ~/.froot/lib/libsfml-graphics.so.2.3 && \
    ln -fs ~/.froot/lib/libsfml-network.so ~/.froot/lib/libsfml-network.so.2.3 && \
    ln -fs ~/.froot/lib/libsfml-system.so ~/.froot/lib/libsfml-system.so.2.3 && \
    ln -fs ~/.froot/lib/libsfml-window.so ~/.froot/lib/libsfml-window.so.2.3 || \
    get_out "Failed to create symbolic links"

echo "Adding variables to your shell configuration. Do not forget to restart it after."

test_and_add_bash ~/.shrc
test_and_add_bash ~/.bashrc
test_and_add_bash ~/.kshrc
test_and_add_bash ~/.zshrc

test_and_add_csh ~/.cshrc
test_and_add_csh ~/.tcshrc

get_out "All bunnies are in!"

