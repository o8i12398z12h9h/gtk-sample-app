    #include "app.h"
    
    void
    button1_clicked_cb (GtkButton * button, App * app)
    {
        GET_UI_ELEMENT (GtkEntry, entry1);
    
        if (gtk_entry_get_text_length (entry1) == 0)
            gtk_entry_set_text (entry1, "test");
        else
            gtk_entry_set_text (entry1, "");
    }
    
    void
    button2_clicked_cb (GtkButton * button, App * app)
    {
        gboolean active;
    
        GET_UI_ELEMENT (GtkSpinner, spinner1);
        GET_UI_ELEMENT (GtkWidget, eventbox1);
    
        g_object_get (G_OBJECT (spinner1), "active", &active,
                      NULL);
    
        if (active) {
            gtk_spinner_stop (spinner1);
            gtk_widget_override_background_color (eventbox1,
                                                  GTK_STATE_FLAG_NORMAL,
                                                  app->
                                                  active_color);
        }
        else {
            gtk_spinner_start (spinner1);
            gtk_widget_override_background_color (eventbox1,
                                                  GTK_STATE_FLAG_NORMAL,
                                                  app->
                                                  inactive_color);
        }
    }
    
    void
    button3_clicked_cb (GtkButton * button, App * app)
    {
        GdkRGBA bg = { 0, 0, 1, 1 };
    
        GET_UI_ELEMENT (GtkWidget, eventbox1);
    
        gtk_widget_override_background_color (eventbox1,
                                              GTK_STATE_FLAG_NORMAL,
                                              &bg);
    }
    
    void
    button4_clicked_cb (GtkButton * button, App * app)
    {
        const gchar *str;
    
        GET_UI_ELEMENT (GtkLabel, label1);
    
        str = gtk_label_get_text (label1);
    
        if (strcmp (str, "label") == 0) {
            gtk_label_set_text (label1, "NewText");
        }
        else {
            gtk_label_set_text (label1, "label");
        }
    }
    
    void
    button5_clicked_cb (GtkButton * button, App * app)
    {
        GET_UI_ELEMENT (GtkWidget, button1);
        GET_UI_ELEMENT (GtkWidget, button2);
        GET_UI_ELEMENT (GtkWidget, button4);
    
        g_signal_emit_by_name (button1, "clicked", app);
        g_signal_emit_by_name (button2, "clicked", app);
        g_signal_emit_by_name (button4, "clicked", app);
    }
