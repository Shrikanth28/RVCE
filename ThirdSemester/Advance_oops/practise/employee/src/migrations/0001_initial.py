# Generated by Django 2.2.5 on 2019-12-30 15:16

from django.db import migrations, models


class Migration(migrations.Migration):

    initial = True

    dependencies = [
    ]

    operations = [
        migrations.CreateModel(
            name='Emp',
            fields=[
                ('id', models.AutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('eid', models.CharField(max_length=30)),
                ('name', models.CharField(max_length=30)),
                ('age', models.IntegerField()),
                ('address', models.TextField()),
            ],
        ),
    ]
