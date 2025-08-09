import setup;
import create_run_task_builder;
import AppBuilder;

auto main() -> int
{
    AppBuilder{}.transform(setup).run(create_run_task_builder());
}
